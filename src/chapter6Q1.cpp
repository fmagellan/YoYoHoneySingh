// Copyright 2020 Magellan.

// Pretend you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows.
// Create an enum to identify the different types of items,
// and an std::array to store the number of each item the player is carrying
// (The enumerators are used as indexes of the array).
// The player should start with 2 health potions, 5 torches, and 10 arrows.
// Write a function called countTotalItems() that returns how many items the player has in total.
// Have your main() function print the output of countTotalItems() as well as the number of torches.

#include <array>
#include <iostream>

// enum class Item_t { // Need to access individual number items in the array with the index.
// So, cannot use class.
enum Item_t {
    HEALTH_POTION,
    TORCH,
    ARROW,
};

auto countTotalItems(const std::array<int, 3> &array) -> int {
    int totalItems{};
    for (auto items: array) {
        totalItems += items;
    }

    return (totalItems);
}

int main() {
    std::array<int, 3> array{};
    array[HEALTH_POTION] = 2;
    array[TORCH] = 5;
    array[ARROW] = 10;

    std::cout << "The total number of items: " << countTotalItems(array) << std::endl;

    return (0);
}
