//
// Created by Sneha Gurung on 11/22/22.
//

#ifndef SFML_HELPER_MOUSEEVENTS_H
#define SFML_HELPER_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>


class MouseEvents {
public:
    template<class T>
    static bool isHovered(const T& Obj, const sf::RenderWindow& window);

    template<class T>
    static bool isClicked(const T& Obj, const sf::RenderWindow& window);

    template<class T>
    static bool isNotClicked(const T& Obj, const sf::RenderWindow& window);

};


#include "MouseEvents.cpp"
#endif //SFML_HELPER_MOUSEEVENTS_H
