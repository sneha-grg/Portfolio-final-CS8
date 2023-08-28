//
// Created by Sneha Gurung on 12/1/22.
//

#ifndef SFML_HELPER_MENU_H
#define SFML_HELPER_MENU_H
#include "List.h"
#include "States.h"
#include <initializer_list>
#include <iostream>


class Menu : public States , public sf::Drawable{
private:
    ListItem header;
    List list;
    void init();

public:
    Menu();
    Menu(std::initializer_list<std::string> items);

    void eventHandler(sf::RenderWindow& window, sf::Event event);

    void update();

    void addItem(std::string item);

    virtual  void draw (sf::RenderTarget& window, sf::RenderStates states) const;

    void setPosition(const sf::Vector2f& position);

};


#endif //SFML_HELPER_MENU_H
