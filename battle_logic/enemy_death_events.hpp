#pragma once

#include "flags_and_variables.hpp"
#include "../entities/enemy_data.hpp"
#include "../interface/main_gui.hpp"

void enemy_death_event() {
    enemy_chars _enemy = enemy_party[current_enemy_character_index];
    
    enemy_party_alive_count--;
    status_line_three = _enemy.get_name() + " HAS BEEN DEFEATED!";

    if (enemy_party_alive_count == 0) {
        trigger_win_event = true;
    } else {
        current_enemy_character_index++;
    }

    trigger_enemy_death_event = false;
}

void player_win_event() {
    status_line_three = "ALL ENEMIES HAVE BEEN DEFEATED! CONGRATULATIONS! GAME WILL CLOSE IN 5 SECONDS...";
    system("CLS");
    main_gui();
}