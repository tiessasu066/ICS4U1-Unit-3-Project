#pragma once

#include <iostream>
#include "../battle_logic/flags_and_variables.hpp"
#include "../entities/classes.hpp"
#include "../entities/player_data.hpp"

std::string item_stats(player_consumables item) {
    std::string _stats;

    //NAME AND TYPE
    _stats = item.get_name() + " [" + item_type_name[item.get_type()] + "]:";

    //HP AND STATS
    _stats += " +" + std::to_string(item.get_additive_amount());    
    return _stats;
}

unsigned short player_item_selection_gui() {
    system("CLS");
    
    std::vector<player_consumables> _inventory = player.get_player_inventory();
    unsigned short _input;

    printf("SELECT WHICH ITEM TO USE:\n");

    for (int i = 0; i < _inventory.size(); i++) {
        printf("\n%hu. %s", (i + 1), item_stats(_inventory[i]).c_str());
    }
   
    printf("\n\n>> ");

    std::cin >> _input;
    std::cin.clear(); std::cin.ignore(256, '\n');
    
    _input--;
    return _input;
}