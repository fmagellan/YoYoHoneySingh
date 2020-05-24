// Copyright Magellan 2020
#include <iostream>

#include "plog/Log.h"

int main() {
    plog::init(plog::debug, "mytemp/traces.txt");

    PLOGD << "Houston, we are in the main";
    PLOGV << "Verbose";
    PLOGD << "Debug";
    PLOGI << "Info";
    PLOGW << "Warning";
    PLOGE << "Error";
    PLOGF << "Fatal";
    PLOGN << "None";

    return (0);
}
