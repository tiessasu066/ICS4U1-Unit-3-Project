#pragma once

#include "flags_and_variables.hpp"
#include "../entities/enemy_data.hpp"
#include "../entities/player_data.hpp"

void determine_attack_order() {
    enemy_chars _enemy = enemy_party[current_enemy_character_index];
    player_chars _player = player.get_player_party()[current_player_character_index];

    if (_player.get_speed() >= _enemy.get_speed()) { //player takes priority if speed is equal
        player_goes_first = true;
    }
}
