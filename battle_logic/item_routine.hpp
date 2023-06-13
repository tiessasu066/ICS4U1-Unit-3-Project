#pragma once

#include "add_attack_modifier_messages.hpp"
#include "flags_and_variables.hpp"
#include "../entities/enemy_data.hpp"
#include "../entities/player_data.hpp"
#include "../interface/player_item_selection_gui.hpp"
#include "enemy_death_events.hpp"
#include "player_death_events.hpp"
#include "damage_logic.hpp"
#include "death_checks.hpp"
#include "flag_reset.hpp"

#include <iostream>

void on_player_use_item() {
    unsigned short _item_index;
    player_chars _current_player = player.get_player_party()[current_player_character_index];
    enemy_chars _enemy = enemy_party[current_enemy_character_index];
    player_consumables _selected_item;
    unsigned short _new_stat;
    
    _item_index = player_item_selection_gui();
    _selected_item = player.get_player_inventory()[_item_index];

    switch (_selected_item.get_type()) {
        case HEAL:
            _new_stat = _current_player.get_hp() + _selected_item.get_additive_amount();

            if (_new_stat > _current_player.get_max_hp()) {
                status_line_one = _current_player.get_name() + " USED A " + _selected_item.get_name() + " AND HEALED TO MAX HP!";
                player.set_player_hp(current_player_character_index, _current_player.get_max_hp()); //ensures that player can't heal past max hp
            } else {
                status_line_one = _current_player.get_name() + " USED A " + _selected_item.get_name() + " AND HEALED 50HP!";
                player.set_player_hp(current_player_character_index, _new_stat);
            }

            player.erase_item(_item_index);
            break;

        case ATK_UP:
            _new_stat = _current_player.get_attack() + _selected_item.get_additive_amount();

            status_line_one = _current_player.get_name() + " USED A " + _selected_item.get_name() + " AND GOT AN EXTRA 10 ATTACK!";
            player.set_player_attack(current_player_character_index, _new_stat);
            player.erase_item(_item_index); 
            break;

        case DEF_UP:
            _new_stat = _current_player.get_defense() + _selected_item.get_additive_amount();

            status_line_one = _current_player.get_name() + " USED A " + _selected_item.get_name() + " AND GOT AN EXTRA 8 DEFENSE!";
            player.set_player_defense(current_player_character_index, _new_stat);
            player.erase_item(_item_index); 
            break;
    }

    player.damage_player(current_player_character_index, total_damage_dealt(_enemy, _current_player));
    status_line_two = _current_player.get_name() + " LOST " + std::to_string(damage_dealt_by_attacker) + " HP!" + add_attack_modifier_string();
    reset_attacker_flags();
    check_player_death();

    if (trigger_player_death_event) {
        player_death_event();
    }

}

