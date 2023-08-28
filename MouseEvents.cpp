//
// Created by Sneha Gurung on 11/22/22.
//

#ifndef SFML_HELPER_MOUSEEVENTS_CPP
#define SFML_HELPER_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template<class T>
bool MouseEvents::isHovered(const T &Obj, const sf::RenderWindow &window)
{
    sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return Obj.getGlobalBounds().contains(m_pos);
}

template<class T>
bool MouseEvents::isClicked(const T &Obj, const sf::RenderWindow &window)
{
    return isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents::isNotClicked(const T &Obj, const sf::RenderWindow &window) {
    return !isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif