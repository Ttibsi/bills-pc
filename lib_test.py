import bpc_cpp as billspc


def main():
    pkmn1 = billspc.Pokemon(
        "Flare", billspc.Species.Charmander, 12, ["Foo", "bar"], False
    )
    pkmn2 = billspc.Pokemon(
        "", billspc.Species.Bulbasaur, 22, ["Foo", "bar"], True
    )

    print("Testing getters")
    print(f"pkmn1 nick: {pkmn1.get_nick()}")
    print(f"pkmn1 species: {pkmn1.get_species()}")
    print(f"pkmn1 level: {pkmn1.get_level()}")
    print(f"pkmn1 moves: {pkmn1.get_moves()}")
    print(f"pkmn1 is shiny: {pkmn1.get_shiny()}")

    print(f"pkmn2 nick: {pkmn2.get_nick()}")
    print(f"pkmn2 species: {pkmn2.get_species()}")
    print(f"pkmn2 level: {pkmn2.get_level()}")
    print(f"pkmn2 moves: {pkmn2.get_moves()}")
    print(f"pkmn2 is shiny: {pkmn2.get_shiny()}")
