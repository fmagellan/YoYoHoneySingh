// Copyright 2020 Magellan
#include <iostream>
#include <string>

enum class MonsterType_t {
    OGRE,
    DRAGON,
    ORC,
    GIANT_SPIDER,
    SLIME
};

struct Monster_t {
    MonsterType_t type;
    std::string name;
    int health;
};

std::string getMonsterTypeString(MonsterType_t type) {
    if (type == MonsterType_t::OGRE) {
        return "Ogre";
    } else if (type == MonsterType_t::DRAGON) {
        return "Dragon";
    } else if (type == MonsterType_t::ORC) {
        return "Orc";
    } else if (type == MonsterType_t::GIANT_SPIDER) {
        return "Giant Spider";
    } else if (type == MonsterType_t::SLIME) {
        return "Slime";
    }

    return "Unknown";
}

void printMonster(Monster_t monster) {
    std::cout << "This " << getMonsterTypeString(monster.type) << " is named " << monster.name << " and has " << monster.health << " health." << std::endl;
}

int main() {
    Monster_t m1{MonsterType_t::OGRE, "Torg", 145};
    printMonster(m1);

    Monster_t m2{MonsterType_t::SLIME, "Blurp", 23};
    printMonster(m2);

    return (0);
}
