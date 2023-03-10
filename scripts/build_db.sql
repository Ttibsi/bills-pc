-- To refactor into:
-- Create Table Pokemon (Primary Id, Name text)
-- Create Table Moves (Primary Id, Name text) -- list of all possible moves
-- Create Table PokemonMoves (Primary Id, PokemonId Id, MoveId Id) constraint Unique (PokemonId, MoveId)

CREATE TABLE ABILITIES (
    ability_id INTEGER NOT NULL PRIMARY KEY,
    name TEXT NOT NULL UNIQUE,
    description TEXT NOT NULL
);

CREATE TABLE POKEMON (
    dex_id INTEGER, -- This is a manual primary key off their pokedex ID
    species TEXT NOT NULL UNIQUE,
    type_1 TEXT NOT NULL,
    type_2 TEXT,
    stat_hp INTEGER NOT NULL,
    stat_atk INTEGER NOT NULL,
    stat_def INTEGER NOT NULL,
    stat_sp_atk INTEGER NOT NULL,
    stat_sp_def INTEGER NOT NULL,
    stat_speed INTEGER NOT NULL,
    ability_1 INTEGER NOT NULL,
    ability_2 INTEGER,
    ability_hidden INTEGER NOT NULL,
    FOREIGN KEY(ability_1) REFERENCES ABILITIES(ability_id),
    FOREIGN KEY(ability_2) REFERENCES ABILITIES(ability_id),
    FOREIGN KEY(ability_hidden) REFERENCES ABILITIES(ability_id)
);

-- TODO: Moves as their own table

CREATE TABLE STORAGE (
    pkmn_id INTEGER PRIMARY KEY AUTOINCREMENT,
    nickname TEXT,
    species INTEGER NOT NULL,
    level INTEGER NOT NULL,
    move_1 TEXT NOT NULL,
    move_2 TEXT,
    move_3 TEXT,
    move_4 TEXT,
    is_shiny BOOLEAN
);
