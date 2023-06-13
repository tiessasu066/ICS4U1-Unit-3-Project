#pragma once

#include "flags_and_variables.hpp"

#include <iostream>

std::string add_attack_modifier_string() {
    std::string output;

    if (is_critical_hit) { output.append(" [CRITICAL HIT!]"); }
    if (elemental_advantage) { output.append(" [2x ELEMENTAL DAMAGE!]"); }
    if (elemental_disadvantage) { output.append(" [0.5x ELEMENTAL DAMAGE...]");}
    
    //if defender dodges then all other attack modifiers are not considered
    if (defender_dodged) { output = " [DODGED!]"; }

    return output;
}

