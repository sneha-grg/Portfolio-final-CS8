//
// Created by Sneha Gurung on 11/22/22.
//

#include "States.h"

std::map<statesEnum, bool> States::map;

States::States() {
    load();
}

void States::load()
{
    for (int i = 0; i < LAST_STATE; i++) {
        map[static_cast<statesEnum>(i)] = false;
    }
}

bool States::checkState(statesEnum state) const
{
    return map[state];
}

void States::enableState(statesEnum state)
{
    setState(state, true);
}

void States::disableState(statesEnum state)
{
    setState(state, false);
}

void States::setState(statesEnum state, bool value)
{
    map.at(state) = value;
}

void States::toggleState(statesEnum state)
{
    setState(state, !map.at(state));
}

