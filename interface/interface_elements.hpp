#pragma once

#include "../battle_logic/flags_and_variables.hpp"
#include "../entities/classes.hpp"
#include <iostream>

void entity_info(entity ent) {
    //general HP bar/stats element
    std::string _name_and_type = ent.get_name() + " [" + element_name[ent.get_type()] + "]:";
    short _num_health_bars = (ent.get_hp() * 60) / ent.get_max_hp();
    std::string _hp = std::to_string(ent.get_hp()) + "/" + std::to_string(ent.get_max_hp());
    std::string _atk = "ATK: " + std::to_string(ent.get_attack());
    std::string _def = "DEF: " + std::to_string(ent.get_defense());
    std::string _speed = "SPEED: " + std::to_string(ent.get_speed());

    //ENTITY NAME [TYPE]: [||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||] HP /MAX, ATK:XX, DEF:XX
    printf("%-22s", _name_and_type.c_str());

    //HEALTH BAR
    printf("[");

    for (int i = 0; i < _num_health_bars; i++) {
        printf("|");
    }

    for (int i = 0; i < 60 - _num_health_bars; i++) {
        printf(" ");
    }

    printf("] ");

    //ENTITY STATS
    printf("%7s, ", _hp.c_str());
    printf("%6s, ", _atk.c_str());
    printf("%6s, ", _def.c_str());
    printf("%6s\n", _speed.c_str());
}

void player_enemy_info(bool choose_enemy_info) {
    //true (1) => choose enemy info instead
    //choose player info by default
    std::string _selected = "PLAYER", living_party_members_indicator;
    unsigned short _party_alive_count = player_party_alive_count;

    if (choose_enemy_info) {
        _selected = "ENEMY";
        _party_alive_count = enemy_party_alive_count;
    }

    //PRINT NAME
    printf("%-7s", _selected.c_str());

    //LIVING PARTY MEMBERS INDICATOR
    printf("[%1hu/3]:\n", _party_alive_count);
}
