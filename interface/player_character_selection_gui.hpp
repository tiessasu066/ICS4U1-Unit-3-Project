#pragma once

#include <iostream>
#include "../battle_logic/flags_and_variables.hpp"
#include "../entities/classes.hpp"
#include "../entities/player_data.hpp"

bool first_selection = true;

std::string player_stats(player_chars player) {
    std::string _stats;

    //NAME AND TYPE
    _stats = player.get_name() + " [" + element_name[player.get_type()] + "]:";

    //HP AND STATS
    _stats += " HP: " + std::to_string(player.get_hp()) + "/" + std::to_string(player.get_max_hp());
    _stats += " ATK: " + std::to_string(player.get_attack()) + " DEF: " + std::to_string(player.get_defense()) + " SPEED: " + std::to_string(player.get_speed());

    return _stats;
}

unsigned short player_character_selection_gui() {
    system("CLS");

    std::vector<player_chars> _player_party = player.get_player_party(), _alive_players;
    std::vector<unsigned int> _alive_player_indexes;
    std::string _title = "SWAP CHARACTER:";
    unsigned short _input;

    //only account for living players
    for (int i = 0; i < _player_party.size(); i++) {
        if (_player_party[i].get_hp() > 0) {
            _alive_players.push_back(_player_party[i]);
            _alive_player_indexes.push_back(i);
        }
    }

    if (trigger_player_death_event) {
        //change title if function was called by death event
        _title = _player_party[current_player_character_index].get_name() + " HAS PERISHED! PLEASE SELECT ANOTHER CHARACTER:";
    }

    if (first_selection) {
        //change title if this is the first character selection (on open)
        _title = "WELCOME TO THE BATTLEFIELD! PLEASE SELECT A CHARACTER TO SEND TO FIGHT:";
        first_selection = false;
    }

    printf("%s\n", _title.c_str());

    for (int i = 0; i < _alive_players.size(); i++) {
        printf("\n%hu. %s", (i + 1), player_stats(_alive_players[i]).c_str());
    }

    printf("\n\n>> ");

    std::cin >> _input;
    std::cin.clear(); std::cin.ignore(256, '\n');
    
    _input--;
    return _alive_player_indexes[_input];
}