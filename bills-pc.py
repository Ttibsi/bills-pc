import argparse
from collections.abc import Sequence
from typing import Union

import bpc_cpp as billspc


def welcome():
    string = "WELCOME TO THE POKEMON STORAGE SYSTEM"
    print(string)
    print("-" * len(string))


def new_entry():
    print("Storing new pokemon")
    species = input("Enter species: ").capitalize()
    nick = input("Enter nickname: ")
    lvl = int(input("Enter level: "))
    shiny = bool(int(input("Is it shiny? (1 for yes, 0 for no): ")))
    moves = [
        s.strip()
        for s in (
            input("Enter moves (up to 4) separated by commas: ").split(",")
        )
    ]

    new_pkmn = billspc.Pokemon(nick, species, lvl, moves, shiny)
    print(f"New Pokemon created: {new_pkmn}")


def list_all():
    print("Listing all pokemon in storage")
    print("+---------------------------------------------+")
    print("| ID | Name | Species | level | Moves | Shiny |")
    print("+=============================================+")

    for pkmn in billspc.get_storage():
        print(
            f"| {pkmn.id} | {pkmn.nickname} | {pkmn.species} | {pkmn.lvl} | {pkmn.moves} | {pkmn.is_shiny} |"  # noqa: E501
        )

    print("+=============================================+")


def remove_entry():
    ...


def main(argv: Union[Sequence[str], None] = None) -> int:
    parser = argparse.ArgumentParser()
    commands = parser.add_mutually_exclusive_group()

    commands.add_argument(
        "--new", help="Add a new pokemon to the database", action="store_true"
    )

    commands.add_argument(
        "--list", help="See all pokemon in storage", action="store_true"
    )

    commands.add_argument(
        "--remove", help="Remove specified pokemon via ID", action="store_true"
    )

    args: argparse.Namespace = parser.parse_args(argv)

    welcome()

    if args.new:
        new_entry()
    elif args.remove:
        remove_entry()
    elif args.list:
        list_all()

    print("Exiting. Goodbye...")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
