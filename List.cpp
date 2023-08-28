//
// Created by Sneha Gurung on 12/1/22.
//

#include "List.h"
#include "Position.h"

void List::addItem(const ListItem &item) {
    items.push_back(item);
    position();
}

void List::addItem(const std::string text, void (*f)()) {
    items.emplace_back(text, sf::Vector2f(200.f, 50.f));
    position();
}

void List::setPosition(const sf::Vector2f &position) {
    items[0].setPosition(position);
    this->position();
}

void List::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN)) {
        for (const ListItem &l: items) {
            target.draw(l);
        }
    }
}

void List::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for (ListItem& l : items) {
        l.eventHandler(window, event);
    }
}

void List::update() {

}

void List::position() {
    for (int i = 1; i < items.size(); ++i) {
        Position::bottom(items[i-1] , items[i]);
    }
}

List::List() {

}

sf::FloatRect List::getGlobalBounds() {
    sf::FloatRect f  = items[0].getGlobalBounds();
    f.height *= items.size();
    return f;
}

std::vector<ListItem> &List::getItems() {
    return items;
}
