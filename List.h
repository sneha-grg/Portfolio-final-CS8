//
// Created by Sneha Gurung on 12/1/22.
//

#ifndef SFML_HELPER_LIST_H
#define SFML_HELPER_LIST_H
#include "ListItem.h"
#include <vector>
#include <string>
#include "States.h"


class List : public sf::Drawable, public States{
private:
    std::vector<ListItem> items;
    void position();

public:
    List();
    void addItem(const ListItem& item);
    void addItem(const std::string text, void (*f)() = nullptr);
    void setPosition(const sf::Vector2f& position);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    sf::FloatRect getGlobalBounds();
    std::vector<ListItem>&  getItems();

};


#endif //SFML_HELPER_LIST_H
