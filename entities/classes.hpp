#pragma once

#include <iostream>
#include <vector>


enum element {FIRE, WATER, GRASS};
std::string element_name[3] = {"FIRE", "WATER", "GRASS"};

enum item_type {HEAL, ATK_UP, DEF_UP};
std::string item_type_name[3] = {"HEAL", "ATTACK UP", "DEFENSE UP"};

class entity {
    public:
        //constructor
        entity(std::string name, element type, short hp, unsigned short attack, unsigned short defense, unsigned short speed) {
            this->name = name;
            this->type = type;
            this->hp = hp;
            this->attack = attack;
            this->defense = defense;
            this->speed = speed;

            max_hp = hp;
        }

        //default constuctor
        entity() {}

        //setter methods
        void set_hp(short hp) { this->hp = hp; }
        void set_defense(unsigned short defense) { this->defense = defense; }
        void set_attack(unsigned short attack) { this->attack = attack; }

        //getter methods
        std::string get_name() {return name;}
        element get_type() {return type;}
        short get_hp() {return hp;}
        unsigned short get_max_hp() {return max_hp;}
        unsigned short get_attack() {return attack;}
        unsigned short get_defense() {return defense;}
        unsigned short get_speed() {return speed;}

        //damage
        void damage(unsigned short damage) { hp -= damage; }
    private:
        std::string name;
        element type;
        short hp;
        unsigned short max_hp, attack, defense, speed;
        bool death_flag = false;
};

class player_consumables {
    public:
        player_consumables(std::string name, item_type type, unsigned short additive_amount) {
            this->name = name;
            this->type = type;
            this->additive_amount = additive_amount;
        }

        player_consumables() {}

        //getter
        std::string get_name() { return name; }
        item_type get_type() { return type; }
        unsigned short get_additive_amount() { return additive_amount; }
    
    private:
        std::string name;
        item_type type;
        unsigned short additive_amount; //general, item's magnitude for all types
};

class enemy_chars : public entity {
    using entity::entity; //use entity constuctor
};

class player_chars : public entity {
    using entity::entity;
};

class player_class {
    public:
        player_class(std::vector<player_chars> player_party, std::vector<player_consumables> inventory) {
            this->player_party = player_party;
            this->inventory = inventory;
        }

        void set_player_hp(int index, short hp) {
            player_party[index].set_hp(hp);
        }
        void set_player_attack(int index, unsigned short attack) {
            player_party[index].set_attack(attack);
        }
        void set_player_defense(int index, unsigned short defense) {
            player_party[index].set_defense(defense);
        }

        void damage_player(int index, unsigned short damage) {
            player_party[index].damage(damage);
        }

        void erase_item(int index) {
            inventory_iterator = inventory.begin() + index;
            inventory.erase(inventory_iterator);
        }

        std::vector<player_chars> get_player_party() {return player_party;}
        std::vector<player_consumables> get_player_inventory() { return inventory; }
    private:
        std::vector<player_consumables>::iterator inventory_iterator;
        std::vector<player_chars> player_party;
        std::vector<player_consumables> inventory;
};


