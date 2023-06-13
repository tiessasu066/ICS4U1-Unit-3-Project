#pragma once

#include "../entities/classes.hpp"

#include "flags_and_variables.hpp"

#include <vector>
#include <random>

//RNG generators
std::default_random_engine generator(time(NULL)); //seeded RNG generators
std::uniform_int_distribution<int> crit_distribution(1,20);
std::uniform_int_distribution<int> dodge_distribution(1,50);


const std::vector<std::vector<float>> elemental_advantage_multiplier { //y = attacker, x = defender
    {1, 0.5, 2},
    {2, 1, 0.5},
    {0.5, 2, 1}
};

float elemental_multiplier(entity attacker, entity defender) {
    float _multiplier = elemental_advantage_multiplier[attacker.get_type()][defender.get_type()];

    if (_multiplier == 2) { elemental_advantage = true; }
    if (_multiplier == 0.5) { elemental_disadvantage = true; }
    
    return _multiplier;
}

float crit_multiplier() {
    if (crit_distribution(generator) == 20) {
        is_critical_hit = true;
        return 2.0;
    }

    return 1.0;
}

bool dodge_multiplier(entity defender) {
    for (int i = 0; i < defender.get_speed(); i++) { //reroll SPEED times
        if (dodge_distribution(generator) == 50) { defender_dodged = true; return 0; }
    }    
    
    return 1;
}

int total_damage_dealt(entity attacker, entity defender) {
    int _damage = float(attacker.get_attack()* (1 - float(defender.get_defense() / 100))) * elemental_multiplier(attacker, defender) * crit_multiplier() * dodge_multiplier(defender); //do floating point math and then floor to an integer

    damage_dealt_by_attacker = _damage;
    return _damage;
}





