#pragma once

#include "add_attack_modifier_messages.hpp"
#include "flags_and_variables.hpp"
#include "../entities/enemy_data.hpp"
#include "../entities/player_data.hpp"
#include "determine_attack_order.hpp"
#include "enemy_death_events.hpp"
#include "player_death_events.hpp"
#include "damage_logic.hpp"
#include "death_checks.hpp"
#include "flag_reset.hpp"

#include <iostream>

void on_player_attack() {
    enemy_chars _enemy = enemy_party[current_enemy_character_index];
    player_chars _player = player.get_player_party()[current_player_character_index];
    
    reset_status_messages();
    determine_attack_order();

    if (player_goes_first) {
        //player speed > enemy speed
        enemy_party[current_enemy_character_index].damage(total_damage_dealt(_player, _enemy));
        status_line_one = _enemy.get_name() + " LOST " + std::to_string(damage_dealt_by_attacker) + " HP!" + add_attack_modifier_string();
        reset_attacker_flags();
        check_enemy_death();

        if (trigger_enemy_death_event) {
            enemy_death_event();
        } else {
            player.damage_player(current_player_character_index, total_damage_dealt(_enemy, _player));
            status_line_two = _player.get_name() + " LOST " + std::to_string(damage_dealt_by_attacker) + " HP!" + add_attack_modifier_string();
            reset_attacker_flags();
            check_player_death();
        }
        
        //run player death event if true
        if (trigger_player_death_event) { 
            player_death_event();
        }
        
    } else {
        //enemy speed > player speed
        player.damage_player(current_player_character_index, total_damage_dealt(_enemy, _player));
        status_line_one = _player.get_name() + " LOST " + std::to_string(damage_dealt_by_attacker) + " HP!" + add_attack_modifier_string();
        reset_attacker_flags();
        check_player_death();

        if (trigger_player_death_event) {
            player_death_event();
        } else {
            enemy_party[current_enemy_character_index].damage(total_damage_dealt(_player, _enemy));
            status_line_two = _enemy.get_name() + " LOST " + std::to_string(damage_dealt_by_attacker) + " HP!" + add_attack_modifier_string();
            reset_attacker_flags();
            check_enemy_death();
        }

        if (trigger_enemy_death_event) {
            enemy_death_event();
        }
    }

    //run victory checks
    if (trigger_win_event) { player_win_event(); }
    if (trigger_loss_event) { player_loss_event(); }
}
