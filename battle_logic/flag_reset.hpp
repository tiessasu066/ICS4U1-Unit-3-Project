#pragma once

#include "flags_and_variables.hpp"

void reset_attacker_flags() {
    damage_dealt_by_attacker = 0;
    is_critical_hit = false;
    elemental_disadvantage = false;
    elemental_advantage = false;
    defender_dodged = false;
}

void reset_death_flags() {
    trigger_enemy_death_event = false;
    trigger_player_death_event = false;
}

void reset_status_messages() {
    status_line_one = "";
    status_line_two = "";
    status_line_three = "";
}