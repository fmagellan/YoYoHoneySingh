// Copyright 2020 Magellan
#include <ctime>
#include <array>
#include <iostream>
#include <string>
#include <string_view>

int generateRandomNumber(const int min, const int max) {
    static constexpr double fraction{ 1.0/(1.0 + static_cast<double>(RAND_MAX)) };
    return (static_cast<int>(std::rand() * fraction * (max - min + 1) + min));
}

class Creature {
 private:
    std::string_view m_name{};
    char m_symbol{};
    int m_health{};
    int m_damagePerAttack{};
    int m_gold{};

 protected:
    Creature() = default;

 public:
    explicit Creature(const std::string_view name, const char symbol, const int health, const int damagePerAttack, const int gold)
        : m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damagePerAttack{ damagePerAttack }, m_gold{ gold } {
    }

    std::string_view getName() const { return (m_name); }
    char getSymbol() const { return (m_symbol); }
    int getHealth() const { return (m_health); }
    int getDamagePerAttack() const { return (m_damagePerAttack); }
    void incrementDamagePerAttack() { ++m_damagePerAttack; }
    int getGold() const { return (m_gold); }

    void reduceHealth(int health) {
        m_health -= health;
    }

    bool isDead() const {
        return (m_health <= 0);
    }

    void addGold(const int gold) {
        m_gold += gold;
        std::cout << "You found " << gold << " gold." << std::endl;
    }
};

class Monster;
class Player : public Creature {
 private:
    int m_level{1};
    std::string m_customName{};

 public:
    Player() : Creature{ "", '@', 10, 1, 0} {
    }

    void levelUp() {
        ++m_level;
        std::cout << "You are now level " << m_level << std::endl;
        incrementDamagePerAttack();
    }

    int getLevel() const { return (m_level); }
    bool hasWon() const {
        return (m_level >= 20);
    }

    std::string getCustomName() const { return (m_customName); }
    void fightMonster();
    void attackMonster(Monster &monster);

    friend std::istream& operator>> (std::istream &in, Player &player);
};

class Monster : public Creature {
 public:
    enum Types {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES,
    };

    struct MonsterData {
        std::string_view m_name;
        char m_symbol;
        int m_health;
        int m_damagePerAttack;
        int m_gold;
    };

    explicit Monster(Monster::Types type)
        : Creature{ m_monsterData[type].m_name, m_monsterData[type].m_symbol, m_monsterData[type].m_health,
            m_monsterData[type].m_damagePerAttack, m_monsterData[type].m_gold} {
    }

    static constexpr MonsterData m_monsterData[Monster::MAX_TYPES] {
        { "dragon", 'D', 20, 4, 100 },
        { "orc", 'O', 4, 2, 25 },
        { "slime", 'S', 1, 1, 10 }
    };

    static Monster::Types getRandomMonster() {
        return (static_cast<Monster::Types>(generateRandomNumber(0, 2)));
    }

    void attackPlayer(Player &player);
};

std::istream& operator>> (std::istream &in, Player &player) {
    in >> player.m_customName;
    return (in);
}

void task_3a() {
    Creature o{ "orc", 'o', 4, 2, 10 };
    o.addGold(5);
    o.reduceHealth(1);
    std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";
}

void task_3b() {
    Player player{};
    std::cout << "Enter your name: ";
    std::cin >> player;
    std::cout << "Welcome " << player.getCustomName() << std::endl;
    std::cout << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold.\n";
}

void task_3c() {
    Monster m{ Monster::ORC };
    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
}

//  handles the player attacking the monster, including leveling up.
void Player::attackMonster(Monster &monster) {
    std::cout << "AttackMonster" << std::endl;
    monster.reduceHealth(getDamagePerAttack());
}

// handles the monster attacking the player.
void Monster::attackPlayer(Player &player) {
    std::cout << "AttackPlayer" << std::endl;
    player.reduceHealth(getDamagePerAttack());
}

//  handles the fight between the Player and a single Monster,
//  including asking the player what they want to do, handling the run or fight cases.
void Player::fightMonster() {
    Monster m{ Monster::getRandomMonster() };
    std::cout << "\nYou have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";
    char choice{};
    std::cout << "(R)un or (F)ight: ";
    std::cin >> choice;
    if ((choice == 'r') || (choice == 'R')) {
        // Toss a coin and see, whether player is able to escape or not.
        bool escapeSuccess{ generateRandomNumber(0, 1) };
        if (escapeSuccess) {
            // Escaped from the monster successfully.
            std::cout << "You successfully fled." << std::endl;
            return;
        } else {
            // Monster gets a free shot at the player !
            std::cout << "You failed to flee." << std::endl;
            m.attackPlayer(*this);
            return;
        }
    } else if ((choice == 'f') || (choice == 'F')) {
        attackMonster(m);
        if (m.getHealth() <= 0) {
            levelUp();
            reduceHealth(1);
            addGold(m.getGold());
        } else {
            m.attackPlayer(*this);
        }
    } else {
        std::cout << "Come back tomorrow." << std::endl;
        return;
    }
}

void task_3d() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // set initial seed value to system clock
    std::rand();  // get rid of first result

    Player player{};
    std::cout << "Enter your name: ";
    std::cin >> player;
    std::cout << "Welcome " << player.getCustomName() << std::endl;
    std::cout << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold.\n";

    while (true) {
        player.fightMonster();
        if (player.getHealth() <= 0) {
            std::cout << "You died at " << player.getLevel() << " and with " << player.getGold() << ".\n";
            std::cout << "Too bad you can't take it with you." << std::endl;
            break;
        }

        if (player.getLevel() >= 20) {
            std::cout << "You reached " << player.getLevel() << " and with " << player.getGold() << ".\n";
            std::cout << "You are the winner !" << std::endl;
            break;
        }
    }
}

int main() {
//    task_3a();
//    task_3b();
//    task_3c();
      task_3d();

    return(0);
}
