// Copyright 2020 Magellan
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string_view>

class Monster {
 public:
    enum Type {
        DRAGON,
        GOBLIN,
        OGRE,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_MONSTER_TYPES,
    };

 private:
    Type m_type{};
    std::string_view m_name{};
    std::string_view m_roar{};
    int m_hitPoints{};

 public:
    explicit Monster(const Type type, const std::string_view name, const std::string_view roar, const int hitPoints)
        : m_type{ type },
        m_name{ name },
        m_roar{ roar },
        m_hitPoints{ hitPoints } {
    }

    const std::string_view getTypeString(const Type type) {
        switch (type) {
            case DRAGON: return ("Dragon");
            case GOBLIN: return ("Goblin");
            case OGRE: return ("Ogre");
            case SKELETON: return ("Skeleton");
            case TROLL: return ("Troll");
            case VAMPIRE: return ("Vampire");
            case ZOMBIE: return ("Zombie");
        }

        return ("Unknown");
    }

    void print() {
        std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hitPoints << " and says " << m_roar << std::endl;
    }
};

class MonsterGenerator {
 public:
     static Monster generateMonster() {
         static constexpr std::string_view m_names[Monster::MAX_MONSTER_TYPES]{
             "DioCletian", "Maximinus", "Antoninus",
                 "Claudius", "Aurelius", "Commodus", "Vespasian" };
         static constexpr std::string_view m_roars[Monster::MAX_MONSTER_TYPES]{
             "*meow*", "*quack*", "*caw*",
                 "*chirp*", "*beep beep*", "*growl*", "*screech*" };

         Monster::Type type { static_cast<Monster::Type>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)) };
         const std::string_view name{ m_names[getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)] };
         const std::string_view roar{ m_roars[getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)] };
         const int hitPoints{ getRandomNumber(0, 100) };

         return (Monster(type, name, roar, hitPoints));
     }

     static int getRandomNumber(int min, int max) {
         static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
         return (static_cast<int>(std::rand() * fraction * (max - min + 1) + min));
     }

 private:
};

int main() {
    Monster skeleton{ Monster::SKELETON, "Bones", "*rattle*", 4 };
    skeleton.print();

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Monster m{ MonsterGenerator::generateMonster() };
    m.print();

    return (0);
}
