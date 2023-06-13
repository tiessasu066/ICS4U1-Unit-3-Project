#pragma once
#include <iostream>
//stores temporary flags and placeholder values that will be referenced and constantly changed
//pseudo ram pretty much

short damage_dealt_by_attacker = 0;
bool is_critical_hit = false;
bool elemental_disadvantage = false;
bool elemental_advantage = false;
bool defender_dodged = false;
bool player_goes_first = false;

bool trigger_enemy_death_event = false;
bool trigger_player_death_event = false;

bool trigger_win_event = false;
bool trigger_loss_event = false;

std::string status_line_one = "";
std::string status_line_two = "";
std::string status_line_three = ""; 

unsigned short current_enemy_character_index = 0;
unsigned short current_player_character_index;

unsigned short enemy_party_alive_count = 3;
unsigned short player_party_alive_count = 3;

