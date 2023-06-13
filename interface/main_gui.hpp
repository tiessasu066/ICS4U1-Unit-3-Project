#pragma once

#include "interface_elements.hpp"
#include "../entities/classes.hpp"
#include "../entities/enemy_data.hpp"
#include "../entities/player_data.hpp"
#include "../battle_logic/flags_and_variables.hpp"

#include <iostream>
#include <stdlib.h>
#include <windows.h>

unsigned short main_gui() {
    unsigned short _input;
    //gets refreshed every input pretty much

    player_enemy_info(1);
    entity_info(enemy_party[current_enemy_character_index]);

    printf("\n");

    player_enemy_info(0);
    entity_info(player.get_player_party()[current_player_character_index]);

    printf("\n> %s", status_line_one.c_str());
    printf("\n> %s", status_line_two.c_str());
    printf("\n> %s", status_line_three.c_str());

    printf("\n\n1. ATTACK        2. ITEMS         3. SWAP CHARACTER\n>> ");

    if (trigger_win_event || trigger_loss_event) {
        //EXIT CASE (GAME OVER)
        Sleep(5000);
        exit(0);
    }

    std::cin >> _input;
    std::cin.clear(); std::cin.ignore(256, '\n');

    return _input;
}