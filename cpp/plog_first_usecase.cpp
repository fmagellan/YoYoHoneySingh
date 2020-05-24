// Copyright Magellan 2020
#include <iostream>

#include "third-party/plog/include/plog/Log.h"

int main() {
    plog::init(plog::debug, "mytemp/traces.txt");

    LOGD << "Houston, we are in the main";

    return (0);
}
