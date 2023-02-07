import sqlite3
from typing import Any
from typing import Dict

import requests

API_BASE = "https://pokeapi.co/api/v2/"
LIMIT = 151  # Gen 1 only


def get_pokemon_names() -> Dict[int, str]:
    ret: Dict[int, str] = {}
    name_url = f"pokemon?limit={LIMIT}"
    req = requests.get(API_BASE + name_url)
    if req.status_code != 200:
        print("Request Error at get_pokemon_names")

    data = req.json()
    for res in data["results"]:
        id = res["url"].split("/")[-2]
        ret[id] = res["name"].capitalize()

    return ret


def insert_abilities_to_database(ability_data: Dict[str, Any]):
    con = sqlite3.connect("db.db")
    cur = con.cursor()

    for ability in ability_data:
        id = ability["ability"]["url"].split("/")[-2]  # type: ignore
        name = ability["ability"]["name"].capitalize()  # type: ignore
        try:
            ability_json = requests.get(
                ability["ability"]["url"]  # type: ignore
            ).json()
            short_str = rf"{ability_json['effect_entries'][1]['short_effect']}"
        except IndexError:
            # Abilities originating in gen8 (SwSh) aren't fully fleshed out
            # in pokeapi
            short_str = ""

        try:
            cur.execute(
                f"""INSERT INTO ABILITIES VALUES (
                    "{id}",
                    "{name.capitalize()}",
                    "{short_str}");"""
            )
        except sqlite3.IntegrityError:
            continue

    con.commit()
    con.close()


def get_ability_id(name: str) -> int:
    con = sqlite3.connect("db.db")
    cur = con.cursor()
    res = cur.execute(
        f"""SELECT ability_id FROM ABILITIES WHERE name == '{
            name.capitalize()}';"""
    ).fetchone()[0]
    con.close()
    return res


def get_species_data(id: int, name: str) -> Dict[str, Any]:
    ret: Dict[str, Any] = {}

    req = requests.get(API_BASE + f"pokemon/{id}")
    if req.status_code != 200:
        print("Request Error at populate_pokemon_data")
    data = req.json()

    ret["dex_id"] = id
    if name == "Nidoran-m":
        ret["species"] = "NidoranM"
    elif name == "Nidoran-f":
        ret["species"] = "NidoranF"
    elif name == "Mr-mime":
        ret["species"] = "MrMime"
    else:
        ret["species"] = name

    ret["type_1"] = data["types"][0]["type"]["name"].capitalize()
    try:
        ret["type_2"] = data["types"][1]["type"]["name"].capitalize()
    except IndexError:
        ret["type_2"] = None

    ret["stat_hp"] = data["stats"][0]["base_stat"]
    ret["stat_atk"] = data["stats"][1]["base_stat"]
    ret["stat_def"] = data["stats"][2]["base_stat"]
    ret["stat_sp_atk"] = data["stats"][3]["base_stat"]
    ret["stat_sp_def"] = data["stats"][4]["base_stat"]
    ret["stat_speed"] = data["stats"][5]["base_stat"]

    insert_abilities_to_database(data["abilities"])

    ret["ability_1"] = get_ability_id(data["abilities"][0]["ability"]["name"])
    if len(data["abilities"]) > 1:
        if data["abilities"][1]["is_hidden"]:
            ret["ability_2"] = None
            ret["ability_hidden"] = get_ability_id(
                data["abilities"][1]["ability"]["name"]
            )
        else:
            ret["ability_2"] = get_ability_id(
                data["abilities"][1]["ability"]["name"]
            )
            ret["ability_hidden"] = get_ability_id(
                data["abilities"][2]["ability"]["name"]
            )
    else:
        ret["ability_2"] = None
        ret["ability_hidden"] = None

    return ret


def populate_pokemon_data(names: Dict[int, str]):
    for id, name in names.items():
        data = get_species_data(id, name)

        con = sqlite3.connect("db.db")
        cur = con.cursor()

        cur.execute(
            f"""INSERT INTO POKEMON VALUES(
            '{data['dex_id']}',
            '{data['species']}',
            '{data['type_1']}',
            '{data['type_2']}',
            '{data['stat_hp']}',
            '{data['stat_atk']}',
            '{data['stat_def']}',
            '{data['stat_sp_atk']}',
            '{data['stat_sp_def']}',
            '{data['stat_speed']}',
            '{data['ability_1']}',
            '{data['ability_2']}',
            '{data['ability_hidden']}'
            )"""
        )

        print(f"Inserting ({data['dex_id']}/{LIMIT}): {data['species']}")
        con.commit()
        con.close()


def main() -> int:
    names: Dict[int, str] = get_pokemon_names()
    populate_pokemon_data(names)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
