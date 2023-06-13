#pragma once

#include "flags_and_variables.hpp"
#include "flag_reset.hpp"
#include "../entities/enemy_data.hpp"
#include "../interface/main_gui.hpp"
#include "../interface/player_character_selection_gui.hpp"

void player_death_event() {
    player_party_alive_count--;

    if (player_party_alive_count == 0) {
        trigger_loss_event = true;
    } else {
        system("CLS");
        current_player_character_index = player_character_selection_gui();
    }

    reset_status_messages();
    trigger_player_death_event = false;
}

void player_loss_event() {
    status_line_three = "ALL YOUR CHARACTERS HAVE PERISHED! BETTER LUCK NEXT TIME! GAME WILL CLOSE IN 5 SECONDS...";
    system("CLS");
    main_gui();
}