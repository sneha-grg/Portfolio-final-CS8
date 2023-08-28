//
// Created by Sneha Gurung on 11/22/22.
//

#ifndef SFML_HELPER_STATES_H
#define SFML_HELPER_STATES_H
#include <map>
#include "statesEnum.h"


class States
{
private:
    static std::map<statesEnum, bool> map;
    void load();

public:
    States();
    bool checkState(statesEnum state) const;
    void enableState(statesEnum state);
    void disableState(statesEnum state);
    void setState(statesEnum state, bool value);
    void toggleState(statesEnum state);

};


#endif //SFML_HELPER_STATES_H
