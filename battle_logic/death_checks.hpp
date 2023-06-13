#pragma once

#include "flags_and_variables.hpp"
#include "../entities/enemy_data.hpp"
#include "../entities/player_data.hpp"

void check_enemy_death() {
    enemy_chars _enemy = enemy_party[current_enemy_character_index];

    if (_enemy.get_hp() <= 0) {
        enemy_party[current_enemy_character_index].set_hp(0);
        trigger_enemy_death_event = true;  
    }
}

void check_player_death() {
    player_chars _player = player.get_player_party()[current_player_character_index];

    if (_player.get_hp() <= 0) {
        player.set_player_hp(current_player_character_index, 0);
        trigger_player_death_event = true;  
    }
}