#pragma once

#include "add_attack_modifier_messages.hpp"
#include "flags_and_variables.hpp"
#include "../entities/enemy_data.hpp"
#include "../entities/player_data.hpp"
#include "../interface/player_character_selection_gui.hpp"
#include "enemy_death_events.hpp"
#include "player_death_events.hpp"
#include "damage_logic.hpp"
#include "death_checks.hpp"
#include "flag_reset.hpp"

#include <iostream>

void on_player_swap_character(bool first_open) {
    enemy_chars _enemy = enemy_party[current_enemy_character_index];
    player_chars _old_player = player.get_player_party()[current_player_character_index], _new_player;

    current_player_character_index = player_character_selection_gui();

    _new_player = player.get_player_party()[current_player_character_index];

    if (!first_open) {
        status_line_one = _old_player.get_name() + " SWAPPED TO " + _new_player.get_name() + "!";

        player.damage_player(current_player_character_index, total_damage_dealt(_enemy, _new_player));
        status_line_two = _new_player.get_name() + " LOST " + std::to_string(damage_dealt_by_attacker) + " HP!" + add_attack_modifier_string();
        reset_attacker_flags();
        check_player_death();

        if (trigger_player_death_event) {
            player_death_event();
        }
    }
}