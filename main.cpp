#include "interface/interface_elements.hpp"

#include "battle_logic/flags_and_variables.hpp"
#include "battle_logic/damage_logic.hpp"
#include "battle_logic/battle_routine.hpp"
#include "battle_logic/swap_routine.hpp"
#include "battle_logic/item_routine.hpp"

#include "entities/classes.hpp"
#include "entities/player_data.hpp"
#include "entities/enemy_data.hpp"

#include "interface/main_gui.hpp"
#include "interface/player_character_selection_gui.hpp"

int main() {
    on_player_swap_character(true);
    system("CLS");

    for (;;) {
        switch(main_gui()) {
            case 1:
                on_player_attack();
                break;
            case 2:
                if (player.get_player_inventory().size() <= 0) {
                    reset_status_messages();
                    status_line_three = "YOU HAVE NO ITEMS LEFT!";
                } else {
                    on_player_use_item();
                }
                break;
            case 3:
                on_player_swap_character(false);
                break;
        }

        system("CLS");
    }
}