#ifndef SPECIES_H
#define SPECIES_H

#include <string>

enum class Species {
    MissingNo,
    Bulbasaur,
    Ivysaur,
    Venusaur,
    Charmander,
    Charmeleon,
    Charizard,
    Squirtle,
    Wartortle,
    Blastoise,
    Caterpie,
    Metapod,
    Butterfree,
    Weedle,
    Kakuna,
    Beedrill,
    Pidgey,
    Pidgeotto,
    Pidgeot,
    Rattata,
    Raticate,
    Spearow,
    Fearow,
    Ekans,
    Arbok,
    Pikachu,
    Raichu,
    Sandshrew,
    Sandslash,
    NidoranF,
    Nidorina,
    Nidoqueen,
    NidoranM,
    Nidorino,
    Nidoking,
    Clefairy,
    Clefable,
    Vulpix,
    Ninetales,
    Jigglypuff,
    Wigglytuff,
    Zubat,
    Golbat,
    Oddish,
    Gloom,
    Vileplume,
    Paras,
    Parasect,
    Venonat,
    Venomoth,
    Diglett,
    Dugtrio,
    Meowth,
    Persian,
    Psyduck,
    Golduck,
    Mankey,
    Primeape,
    Growlithe,
    Arcanine,
    Poliwag,
    Poliwhirl,
    Poliwrath,
    Abra,
    Kadabra,
    Alakazam,
    Machop,
    Machoke,
    Machamp,
    Bellsprout,
    Weepinbell,
    Victreebel,
    Tentacool,
    Tentacruel,
    Geodude,
    Graveler,
    Golem,
    Ponyta,
    Rapidash,
    Slowpoke,
    Slowbro,
    Magnemite,
    Magneton,
    Farfetchd,
    Doduo,
    Dodrio,
    Seel,
    Dewgong,
    Grimer,
    Muk,
    Shellder,
    Cloyster,
    Gastly,
    Haunter,
    Gengar,
    Onix,
    Drowzee,
    Hypno,
    Krabby,
    Kingler,
    Voltorb,
    Electrode,
    Exeggcute,
    Exeggutor,
    Cubone,
    Marowak,
    Hitmonlee,
    Hitmonchan,
    Lickitung,
    Koffing,
    Weezing,
    Rhyhorn,
    Rhydon,
    Chansey,
    Tangela,
    Kangaskhan,
    Horsea,
    Seadra,
    Goldeen,
    Seaking,
    Staryu,
    Starmie,
    MrMime,
    Scyther,
    Jynx,
    Electabuzz,
    Magmar,
    Pinsir,
    Tauros,
    Magikarp,
    Gyarados,
    Lapras,
    Ditto,
    Eevee,
    Vaporeon,
    Jolteon,
    Flareon,
    Porygon,
    Omanyte,
    Omastar,
    Kabuto,
    Kabutops,
    Aerodactyl,
    Snorlax,
    Articuno,
    Zapdos,
    Moltres,
    Dratini,
    Dragonair,
    Dragonite,
    Mewtwo,
    Mew,
};

std::string inline species_stringify(Species sp) {
    switch (sp) {
    case Species::Bulbasaur:
        return std::string("Bulbasaur");
    case Species::Ivysaur:
        return std::string("Ivysaur");
    case Species::Venusaur:
        return std::string("Venusaur");
    case Species::Charmander:
        return std::string("Charmander");
    case Species::Charmeleon:
        return std::string("Charmeleon");
    case Species::Charizard:
        return std::string("Charizard");
    case Species::Squirtle:
        return std::string("Squirtle");
    case Species::Wartortle:
        return std::string("Wartortle");
    case Species::Blastoise:
        return std::string("Blastoise");
    case Species::Caterpie:
        return std::string("Caterpie");
    case Species::Metapod:
        return std::string("Metapod");
    case Species::Butterfree:
        return std::string("Butterfree");
    case Species::Weedle:
        return std::string("Weedle");
    case Species::Kakuna:
        return std::string("Kakuna");
    case Species::Beedrill:
        return std::string("Beedrill");
    case Species::Pidgey:
        return std::string("Pidgey");
    case Species::Pidgeotto:
        return std::string("Pidgeotto");
    case Species::Pidgeot:
        return std::string("Pidgeot");
    case Species::Rattata:
        return std::string("Rattata");
    case Species::Raticate:
        return std::string("Raticate");
    case Species::Spearow:
        return std::string("Spearow");
    case Species::Fearow:
        return std::string("Fearow");
    case Species::Ekans:
        return std::string("Ekans");
    case Species::Arbok:
        return std::string("Arbok");
    case Species::Pikachu:
        return std::string("Pikachu");
    case Species::Raichu:
        return std::string("Raichu");
    case Species::Sandshrew:
        return std::string("Sandshrew");
    case Species::Sandslash:
        return std::string("Sandslash");
    case Species::NidoranF:
        return std::string("NidoranF");
    case Species::Nidorina:
        return std::string("Nidorina");
    case Species::Nidoqueen:
        return std::string("Nidoqueen");
    case Species::NidoranM:
        return std::string("NidoranM");
    case Species::Nidorino:
        return std::string("Nidorino");
    case Species::Nidoking:
        return std::string("Nidoking");
    case Species::Clefairy:
        return std::string("Clefairy");
    case Species::Clefable:
        return std::string("Clefable");
    case Species::Vulpix:
        return std::string("Vulpix");
    case Species::Ninetales:
        return std::string("Ninetales");
    case Species::Jigglypuff:
        return std::string("Jigglypuff");
    case Species::Wigglytuff:
        return std::string("Wigglytuff");
    case Species::Zubat:
        return std::string("Zubat");
    case Species::Golbat:
        return std::string("Golbat");
    case Species::Oddish:
        return std::string("Oddish");
    case Species::Gloom:
        return std::string("Gloom");
    case Species::Vileplume:
        return std::string("Vileplume");
    case Species::Paras:
        return std::string("Paras");
    case Species::Parasect:
        return std::string("Parasect");
    case Species::Venonat:
        return std::string("Venonat");
    case Species::Venomoth:
        return std::string("Venomoth");
    case Species::Diglett:
        return std::string("Diglett");
    case Species::Dugtrio:
        return std::string("Dugtrio");
    case Species::Meowth:
        return std::string("Meowth");
    case Species::Persian:
        return std::string("Persian");
    case Species::Psyduck:
        return std::string("Psyduck");
    case Species::Golduck:
        return std::string("Golduck");
    case Species::Mankey:
        return std::string("Mankey");
    case Species::Primeape:
        return std::string("Primeape");
    case Species::Growlithe:
        return std::string("Growlithe");
    case Species::Arcanine:
        return std::string("Arcanine");
    case Species::Poliwag:
        return std::string("Poliwag");
    case Species::Poliwhirl:
        return std::string("Poliwhirl");
    case Species::Poliwrath:
        return std::string("Poliwrath");
    case Species::Abra:
        return std::string("Abra");
    case Species::Kadabra:
        return std::string("Kadabra");
    case Species::Alakazam:
        return std::string("Alakazam");
    case Species::Machop:
        return std::string("Machop");
    case Species::Machoke:
        return std::string("Machoke");
    case Species::Machamp:
        return std::string("Machamp");
    case Species::Bellsprout:
        return std::string("Bellsprout");
    case Species::Weepinbell:
        return std::string("Weepinbell");
    case Species::Victreebel:
        return std::string("Victreebel");
    case Species::Tentacool:
        return std::string("Tentacool");
    case Species::Tentacruel:
        return std::string("Tentacruel");
    case Species::Geodude:
        return std::string("Geodude");
    case Species::Graveler:
        return std::string("Graveler");
    case Species::Golem:
        return std::string("Golem");
    case Species::Ponyta:
        return std::string("Ponyta");
    case Species::Rapidash:
        return std::string("Rapidash");
    case Species::Slowpoke:
        return std::string("Slowpoke");
    case Species::Slowbro:
        return std::string("Slowbro");
    case Species::Magnemite:
        return std::string("Magnemite");
    case Species::Magneton:
        return std::string("Magneton");
    case Species::Farfetchd:
        return std::string("Farfetchd");
    case Species::Doduo:
        return std::string("Doduo");
    case Species::Dodrio:
        return std::string("Dodrio");
    case Species::Seel:
        return std::string("Seel");
    case Species::Dewgong:
        return std::string("Dewgong");
    case Species::Grimer:
        return std::string("Grimer");
    case Species::Muk:
        return std::string("Muk");
    case Species::Shellder:
        return std::string("Shellder");
    case Species::Cloyster:
        return std::string("Cloyster");
    case Species::Gastly:
        return std::string("Gastly");
    case Species::Haunter:
        return std::string("Haunter");
    case Species::Gengar:
        return std::string("Gengar");
    case Species::Onix:
        return std::string("Onix");
    case Species::Drowzee:
        return std::string("Drowzee");
    case Species::Hypno:
        return std::string("Hypno");
    case Species::Krabby:
        return std::string("Krabby");
    case Species::Kingler:
        return std::string("Kingler");
    case Species::Voltorb:
        return std::string("Voltorb");
    case Species::Electrode:
        return std::string("Electrode");
    case Species::Exeggcute:
        return std::string("Exeggcute");
    case Species::Exeggutor:
        return std::string("Exeggutor");
    case Species::Cubone:
        return std::string("Cubone");
    case Species::Marowak:
        return std::string("Marowak");
    case Species::Hitmonlee:
        return std::string("Hitmonlee");
    case Species::Hitmonchan:
        return std::string("Hitmonchan");
    case Species::Lickitung:
        return std::string("Lickitung");
    case Species::Koffing:
        return std::string("Koffing");
    case Species::Weezing:
        return std::string("Weezing");
    case Species::Rhyhorn:
        return std::string("Rhyhorn");
    case Species::Rhydon:
        return std::string("Rhydon");
    case Species::Chansey:
        return std::string("Chansey");
    case Species::Tangela:
        return std::string("Tangela");
    case Species::Kangaskhan:
        return std::string("Kangaskhan");
    case Species::Horsea:
        return std::string("Horsea");
    case Species::Seadra:
        return std::string("Seadra");
    case Species::Goldeen:
        return std::string("Goldeen");
    case Species::Seaking:
        return std::string("Seaking");
    case Species::Staryu:
        return std::string("Staryu");
    case Species::Starmie:
        return std::string("Starmie");
    case Species::MrMime:
        return std::string("MrMime");
    case Species::Scyther:
        return std::string("Scyther");
    case Species::Jynx:
        return std::string("Jynx");
    case Species::Electabuzz:
        return std::string("Electabuzz");
    case Species::Magmar:
        return std::string("Magmar");
    case Species::Pinsir:
        return std::string("Pinsir");
    case Species::Tauros:
        return std::string("Tauros");
    case Species::Magikarp:
        return std::string("Magikarp");
    case Species::Gyarados:
        return std::string("Gyarados");
    case Species::Lapras:
        return std::string("Lapras");
    case Species::Ditto:
        return std::string("Ditto");
    case Species::Eevee:
        return std::string("Eevee");
    case Species::Vaporeon:
        return std::string("Vaporeon");
    case Species::Jolteon:
        return std::string("Jolteon");
    case Species::Flareon:
        return std::string("Flareon");
    case Species::Porygon:
        return std::string("Porygon");
    case Species::Omanyte:
        return std::string("Omanyte");
    case Species::Omastar:
        return std::string("Omastar");
    case Species::Kabuto:
        return std::string("Kabuto");
    case Species::Kabutops:
        return std::string("Kabutops");
    case Species::Aerodactyl:
        return std::string("Aerodactyl");
    case Species::Snorlax:
        return std::string("Snorlax");
    case Species::Articuno:
        return std::string("Articuno");
    case Species::Zapdos:
        return std::string("Zapdos");
    case Species::Moltres:
        return std::string("Moltres");
    case Species::Dratini:
        return std::string("Dratini");
    case Species::Dragonair:
        return std::string("Dragonair");
    case Species::Dragonite:
        return std::string("Dragonite");
    case Species::Mewtwo:
        return std::string("Mewtwo");
    case Species::Mew:
        return std::string("Mew");
    default:
        return std::string("");
    }
}

Species inline to_species(std::string inp) {
    if (inp == "Bulbasaur")
        return Species::Bulbasaur;
    if (inp == "Ivysaur")
        return Species::Ivysaur;
    if (inp == "Venusaur")
        return Species::Venusaur;
    if (inp == "Charmander")
        return Species::Charmander;
    if (inp == "Charmeleon")
        return Species::Charmeleon;
    if (inp == "Charizard")
        return Species::Charizard;
    if (inp == "Squirtle")
        return Species::Squirtle;
    if (inp == "Wartortle")
        return Species::Wartortle;
    if (inp == "Blastoise")
        return Species::Blastoise;
    if (inp == "Caterpie")
        return Species::Caterpie;
    if (inp == "Metapod")
        return Species::Metapod;
    if (inp == "Butterfree")
        return Species::Butterfree;
    if (inp == "Weedle")
        return Species::Weedle;
    if (inp == "Kakuna")
        return Species::Kakuna;
    if (inp == "Beedrill")
        return Species::Beedrill;
    if (inp == "Pidgey")
        return Species::Pidgey;
    if (inp == "Pidgeotto")
        return Species::Pidgeotto;
    if (inp == "Pidgeot")
        return Species::Pidgeot;
    if (inp == "Rattata")
        return Species::Rattata;
    if (inp == "Raticate")
        return Species::Raticate;
    if (inp == "Spearow")
        return Species::Spearow;
    if (inp == "Fearow")
        return Species::Fearow;
    if (inp == "Ekans")
        return Species::Ekans;
    if (inp == "Arbok")
        return Species::Arbok;
    if (inp == "Pikachu")
        return Species::Pikachu;
    if (inp == "Raichu")
        return Species::Raichu;
    if (inp == "Sandshrew")
        return Species::Sandshrew;
    if (inp == "Sandslash")
        return Species::Sandslash;
    if (inp == "NidoranF")
        return Species::NidoranF;
    if (inp == "Nidorina")
        return Species::Nidorina;
    if (inp == "Nidoqueen")
        return Species::Nidoqueen;
    if (inp == "NidoranM")
        return Species::NidoranM;
    if (inp == "Nidorino")
        return Species::Nidorino;
    if (inp == "Nidoking")
        return Species::Nidoking;
    if (inp == "Clefairy")
        return Species::Clefairy;
    if (inp == "Clefable")
        return Species::Clefable;
    if (inp == "Vulpix")
        return Species::Vulpix;
    if (inp == "Ninetales")
        return Species::Ninetales;
    if (inp == "Jigglypuff")
        return Species::Jigglypuff;
    if (inp == "Wigglytuff")
        return Species::Wigglytuff;
    if (inp == "Zubat")
        return Species::Zubat;
    if (inp == "Golbat")
        return Species::Golbat;
    if (inp == "Oddish")
        return Species::Oddish;
    if (inp == "Gloom")
        return Species::Gloom;
    if (inp == "Vileplume")
        return Species::Vileplume;
    if (inp == "Paras")
        return Species::Paras;
    if (inp == "Parasect")
        return Species::Parasect;
    if (inp == "Venonat")
        return Species::Venonat;
    if (inp == "Venomoth")
        return Species::Venomoth;
    if (inp == "Diglett")
        return Species::Diglett;
    if (inp == "Dugtrio")
        return Species::Dugtrio;
    if (inp == "Meowth")
        return Species::Meowth;
    if (inp == "Persian")
        return Species::Persian;
    if (inp == "Psyduck")
        return Species::Psyduck;
    if (inp == "Golduck")
        return Species::Golduck;
    if (inp == "Mankey")
        return Species::Mankey;
    if (inp == "Primeape")
        return Species::Primeape;
    if (inp == "Growlithe")
        return Species::Growlithe;
    if (inp == "Arcanine")
        return Species::Arcanine;
    if (inp == "Poliwag")
        return Species::Poliwag;
    if (inp == "Poliwhirl")
        return Species::Poliwhirl;
    if (inp == "Poliwrath")
        return Species::Poliwrath;
    if (inp == "Abra")
        return Species::Abra;
    if (inp == "Kadabra")
        return Species::Kadabra;
    if (inp == "Alakazam")
        return Species::Alakazam;
    if (inp == "Machop")
        return Species::Machop;
    if (inp == "Machoke")
        return Species::Machoke;
    if (inp == "Machamp")
        return Species::Machamp;
    if (inp == "Bellsprout")
        return Species::Bellsprout;
    if (inp == "Weepinbell")
        return Species::Weepinbell;
    if (inp == "Victreebel")
        return Species::Victreebel;
    if (inp == "Tentacool")
        return Species::Tentacool;
    if (inp == "Tentacruel")
        return Species::Tentacruel;
    if (inp == "Geodude")
        return Species::Geodude;
    if (inp == "Graveler")
        return Species::Graveler;
    if (inp == "Golem")
        return Species::Golem;
    if (inp == "Ponyta")
        return Species::Ponyta;
    if (inp == "Rapidash")
        return Species::Rapidash;
    if (inp == "Slowpoke")
        return Species::Slowpoke;
    if (inp == "Slowbro")
        return Species::Slowbro;
    if (inp == "Magnemite")
        return Species::Magnemite;
    if (inp == "Magneton")
        return Species::Magneton;
    if (inp == "Farfetchd")
        return Species::Farfetchd;
    if (inp == "Doduo")
        return Species::Doduo;
    if (inp == "Dodrio")
        return Species::Dodrio;
    if (inp == "Seel")
        return Species::Seel;
    if (inp == "Dewgong")
        return Species::Dewgong;
    if (inp == "Grimer")
        return Species::Grimer;
    if (inp == "Muk")
        return Species::Muk;
    if (inp == "Shellder")
        return Species::Shellder;
    if (inp == "Cloyster")
        return Species::Cloyster;
    if (inp == "Gastly")
        return Species::Gastly;
    if (inp == "Haunter")
        return Species::Haunter;
    if (inp == "Gengar")
        return Species::Gengar;
    if (inp == "Onix")
        return Species::Onix;
    if (inp == "Drowzee")
        return Species::Drowzee;
    if (inp == "Hypno")
        return Species::Hypno;
    if (inp == "Krabby")
        return Species::Krabby;
    if (inp == "Kingler")
        return Species::Kingler;
    if (inp == "Voltorb")
        return Species::Voltorb;
    if (inp == "Electrode")
        return Species::Electrode;
    if (inp == "Exeggcute")
        return Species::Exeggcute;
    if (inp == "Exeggutor")
        return Species::Exeggutor;
    if (inp == "Cubone")
        return Species::Cubone;
    if (inp == "Marowak")
        return Species::Marowak;
    if (inp == "Hitmonlee")
        return Species::Hitmonlee;
    if (inp == "Hitmonchan")
        return Species::Hitmonchan;
    if (inp == "Lickitung")
        return Species::Lickitung;
    if (inp == "Koffing")
        return Species::Koffing;
    if (inp == "Weezing")
        return Species::Weezing;
    if (inp == "Rhyhorn")
        return Species::Rhyhorn;
    if (inp == "Rhydon")
        return Species::Rhydon;
    if (inp == "Chansey")
        return Species::Chansey;
    if (inp == "Tangela")
        return Species::Tangela;
    if (inp == "Kangaskhan")
        return Species::Kangaskhan;
    if (inp == "Horsea")
        return Species::Horsea;
    if (inp == "Seadra")
        return Species::Seadra;
    if (inp == "Goldeen")
        return Species::Goldeen;
    if (inp == "Seaking")
        return Species::Seaking;
    if (inp == "Staryu")
        return Species::Staryu;
    if (inp == "Starmie")
        return Species::Starmie;
    if (inp == "MrMime")
        return Species::MrMime;
    if (inp == "Scyther")
        return Species::Scyther;
    if (inp == "Jynx")
        return Species::Jynx;
    if (inp == "Electabuzz")
        return Species::Electabuzz;
    if (inp == "Magmar")
        return Species::Magmar;
    if (inp == "Pinsir")
        return Species::Pinsir;
    if (inp == "Tauros")
        return Species::Tauros;
    if (inp == "Magikarp")
        return Species::Magikarp;
    if (inp == "Gyarados")
        return Species::Gyarados;
    if (inp == "Lapras")
        return Species::Lapras;
    if (inp == "Ditto")
        return Species::Ditto;
    if (inp == "Eevee")
        return Species::Eevee;
    if (inp == "Vaporeon")
        return Species::Vaporeon;
    if (inp == "Jolteon")
        return Species::Jolteon;
    if (inp == "Flareon")
        return Species::Flareon;
    if (inp == "Porygon")
        return Species::Porygon;
    if (inp == "Omanyte")
        return Species::Omanyte;
    if (inp == "Omastar")
        return Species::Omastar;
    if (inp == "Kabuto")
        return Species::Kabuto;
    if (inp == "Kabutops")
        return Species::Kabutops;
    if (inp == "Aerodactyl")
        return Species::Aerodactyl;
    if (inp == "Snorlax")
        return Species::Snorlax;
    if (inp == "Articuno")
        return Species::Articuno;
    if (inp == "Zapdos")
        return Species::Zapdos;
    if (inp == "Moltres")
        return Species::Moltres;
    if (inp == "Dratini")
        return Species::Dratini;
    if (inp == "Dragonair")
        return Species::Dragonair;
    if (inp == "Dragonite")
        return Species::Dragonite;
    if (inp == "Mewtwo")
        return Species::Mewtwo;
    if (inp == "Mew")
        return Species::Mew;
    if (inp == "Bulbasaur")
        return Species::Bulbasaur;
    if (inp == "Ivysaur")
        return Species::Ivysaur;
    if (inp == "Venusaur")
        return Species::Venusaur;
    if (inp == "Charmander")
        return Species::Charmander;
    if (inp == "Charmeleon")
        return Species::Charmeleon;
    if (inp == "Charizard")
        return Species::Charizard;
    if (inp == "Squirtle")
        return Species::Squirtle;
    if (inp == "Wartortle")
        return Species::Wartortle;
    if (inp == "Blastoise")
        return Species::Blastoise;
    if (inp == "Caterpie")
        return Species::Caterpie;
    if (inp == "Metapod")
        return Species::Metapod;
    if (inp == "Butterfree")
        return Species::Butterfree;
    if (inp == "Weedle")
        return Species::Weedle;
    if (inp == "Kakuna")
        return Species::Kakuna;
    if (inp == "Beedrill")
        return Species::Beedrill;
    if (inp == "Pidgey")
        return Species::Pidgey;
    if (inp == "Pidgeotto")
        return Species::Pidgeotto;
    if (inp == "Pidgeot")
        return Species::Pidgeot;
    if (inp == "Rattata")
        return Species::Rattata;
    if (inp == "Raticate")
        return Species::Raticate;
    if (inp == "Spearow")
        return Species::Spearow;
    if (inp == "Fearow")
        return Species::Fearow;
    if (inp == "Ekans")
        return Species::Ekans;
    if (inp == "Arbok")
        return Species::Arbok;
    if (inp == "Pikachu")
        return Species::Pikachu;
    if (inp == "Raichu")
        return Species::Raichu;
    if (inp == "Sandshrew")
        return Species::Sandshrew;
    if (inp == "Sandslash")
        return Species::Sandslash;
    if (inp == "NidoranF")
        return Species::NidoranF;
    if (inp == "Nidorina")
        return Species::Nidorina;
    if (inp == "Nidoqueen")
        return Species::Nidoqueen;
    if (inp == "NidoranM")
        return Species::NidoranM;
    if (inp == "Nidorino")
        return Species::Nidorino;
    if (inp == "Nidoking")
        return Species::Nidoking;
    if (inp == "Clefairy")
        return Species::Clefairy;
    if (inp == "Clefable")
        return Species::Clefable;
    if (inp == "Vulpix")
        return Species::Vulpix;
    if (inp == "Ninetales")
        return Species::Ninetales;
    if (inp == "Jigglypuff")
        return Species::Jigglypuff;
    if (inp == "Wigglytuff")
        return Species::Wigglytuff;
    if (inp == "Zubat")
        return Species::Zubat;
    if (inp == "Golbat")
        return Species::Golbat;
    if (inp == "Oddish")
        return Species::Oddish;
    if (inp == "Gloom")
        return Species::Gloom;
    if (inp == "Vileplume")
        return Species::Vileplume;
    if (inp == "Paras")
        return Species::Paras;
    if (inp == "Parasect")
        return Species::Parasect;
    if (inp == "Venonat")
        return Species::Venonat;
    if (inp == "Venomoth")
        return Species::Venomoth;
    if (inp == "Diglett")
        return Species::Diglett;
    if (inp == "Dugtrio")
        return Species::Dugtrio;
    if (inp == "Meowth")
        return Species::Meowth;
    if (inp == "Persian")
        return Species::Persian;
    if (inp == "Psyduck")
        return Species::Psyduck;
    if (inp == "Golduck")
        return Species::Golduck;
    if (inp == "Mankey")
        return Species::Mankey;
    if (inp == "Primeape")
        return Species::Primeape;
    if (inp == "Growlithe")
        return Species::Growlithe;
    if (inp == "Arcanine")
        return Species::Arcanine;
    if (inp == "Poliwag")
        return Species::Poliwag;
    if (inp == "Poliwhirl")
        return Species::Poliwhirl;
    if (inp == "Poliwrath")
        return Species::Poliwrath;
    if (inp == "Abra")
        return Species::Abra;
    if (inp == "Kadabra")
        return Species::Kadabra;
    if (inp == "Alakazam")
        return Species::Alakazam;
    if (inp == "Machop")
        return Species::Machop;
    if (inp == "Machoke")
        return Species::Machoke;
    if (inp == "Machamp")
        return Species::Machamp;
    if (inp == "Bellsprout")
        return Species::Bellsprout;
    if (inp == "Weepinbell")
        return Species::Weepinbell;
    if (inp == "Victreebel")
        return Species::Victreebel;
    if (inp == "Tentacool")
        return Species::Tentacool;
    if (inp == "Tentacruel")
        return Species::Tentacruel;
    if (inp == "Geodude")
        return Species::Geodude;
    if (inp == "Graveler")
        return Species::Graveler;
    if (inp == "Golem")
        return Species::Golem;
    if (inp == "Ponyta")
        return Species::Ponyta;
    if (inp == "Rapidash")
        return Species::Rapidash;
    if (inp == "Slowpoke")
        return Species::Slowpoke;
    if (inp == "Slowbro")
        return Species::Slowbro;
    if (inp == "Magnemite")
        return Species::Magnemite;
    if (inp == "Magneton")
        return Species::Magneton;
    if (inp == "Farfetchd")
        return Species::Farfetchd;
    if (inp == "Doduo")
        return Species::Doduo;
    if (inp == "Dodrio")
        return Species::Dodrio;
    if (inp == "Seel")
        return Species::Seel;
    if (inp == "Dewgong")
        return Species::Dewgong;
    if (inp == "Grimer")
        return Species::Grimer;
    if (inp == "Muk")
        return Species::Muk;
    if (inp == "Shellder")
        return Species::Shellder;
    if (inp == "Cloyster")
        return Species::Cloyster;
    if (inp == "Gastly")
        return Species::Gastly;
    if (inp == "Haunter")
        return Species::Haunter;
    if (inp == "Gengar")
        return Species::Gengar;
    if (inp == "Onix")
        return Species::Onix;
    if (inp == "Drowzee")
        return Species::Drowzee;
    if (inp == "Hypno")
        return Species::Hypno;
    if (inp == "Krabby")
        return Species::Krabby;
    if (inp == "Kingler")
        return Species::Kingler;
    if (inp == "Voltorb")
        return Species::Voltorb;
    if (inp == "Electrode")
        return Species::Electrode;
    if (inp == "Exeggcute")
        return Species::Exeggcute;
    if (inp == "Exeggutor")
        return Species::Exeggutor;
    if (inp == "Cubone")
        return Species::Cubone;
    if (inp == "Marowak")
        return Species::Marowak;
    if (inp == "Hitmonlee")
        return Species::Hitmonlee;
    if (inp == "Hitmonchan")
        return Species::Hitmonchan;
    if (inp == "Lickitung")
        return Species::Lickitung;
    if (inp == "Koffing")
        return Species::Koffing;
    if (inp == "Weezing")
        return Species::Weezing;
    if (inp == "Rhyhorn")
        return Species::Rhyhorn;
    if (inp == "Rhydon")
        return Species::Rhydon;
    if (inp == "Chansey")
        return Species::Chansey;
    if (inp == "Tangela")
        return Species::Tangela;
    if (inp == "Kangaskhan")
        return Species::Kangaskhan;
    if (inp == "Horsea")
        return Species::Horsea;
    if (inp == "Seadra")
        return Species::Seadra;
    if (inp == "Goldeen")
        return Species::Goldeen;
    if (inp == "Seaking")
        return Species::Seaking;
    if (inp == "Staryu")
        return Species::Staryu;
    if (inp == "Starmie")
        return Species::Starmie;
    if (inp == "MrMime")
        return Species::MrMime;
    if (inp == "Scyther")
        return Species::Scyther;
    if (inp == "Jynx")
        return Species::Jynx;
    if (inp == "Electabuzz")
        return Species::Electabuzz;
    if (inp == "Magmar")
        return Species::Magmar;
    if (inp == "Pinsir")
        return Species::Pinsir;
    if (inp == "Tauros")
        return Species::Tauros;
    if (inp == "Magikarp")
        return Species::Magikarp;
    if (inp == "Gyarados")
        return Species::Gyarados;
    if (inp == "Lapras")
        return Species::Lapras;
    if (inp == "Ditto")
        return Species::Ditto;
    if (inp == "Eevee")
        return Species::Eevee;
    if (inp == "Vaporeon")
        return Species::Vaporeon;
    if (inp == "Jolteon")
        return Species::Jolteon;
    if (inp == "Flareon")
        return Species::Flareon;
    if (inp == "Porygon")
        return Species::Porygon;
    if (inp == "Omanyte")
        return Species::Omanyte;
    if (inp == "Omastar")
        return Species::Omastar;
    if (inp == "Kabuto")
        return Species::Kabuto;
    if (inp == "Kabutops")
        return Species::Kabutops;
    if (inp == "Aerodactyl")
        return Species::Aerodactyl;
    if (inp == "Snorlax")
        return Species::Snorlax;
    if (inp == "Articuno")
        return Species::Articuno;
    if (inp == "Zapdos")
        return Species::Zapdos;
    if (inp == "Moltres")
        return Species::Moltres;
    if (inp == "Dratini")
        return Species::Dratini;
    if (inp == "Dragonair")
        return Species::Dragonair;
    if (inp == "Dragonite")
        return Species::Dragonite;
    if (inp == "Mewtwo")
        return Species::Mewtwo;
    if (inp == "Mew")
        return Species::Mew;

    return Species::MissingNo;
}

#endif
