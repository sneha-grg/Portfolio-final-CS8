//
// Created by Sneha Gurung on 12/1/22.
//

#include "Menu.h"
#include "Position.h"
#include "MouseEvents.h"

Menu::Menu() {
}

Menu::Menu(std::initializer_list<std::string> items)  {
    std::initializer_list<std::string> ::iterator iter = items.begin();
    header.setString(*iter);
    header.setBoxSize({200,50});
    ++iter;
    for (;iter!= items.end(); ++iter) {
        list.addItem(*iter);
    }
    init();
}

void Menu::eventHandler(sf::RenderWindow &window, sf::Event event) {
    list.eventHandler(window, event);
    header.eventHandler(window, event);
    if(MouseEvents::isClicked(header, window)){
        list.disableState(HIDDEN);
    }
    else if(MouseEvents::isNotClicked(header, window)){
        std::string s;
        for (ListItem& l : list.getItems()) {
            if(MouseEvents::isClicked(l , window)){
                if(l.getString() == "Resize") { // TWEAK
                    window.setSize({1920, 1080});
                }
            }
        }
        list.enableState(HIDDEN);
    }
}

void Menu::update() {

}

void Menu::addItem(std::string item) {
    list.addItem(item);
}

void Menu::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(header);
    window.draw(list);
}

void Menu::init() {
    list.enableState(HIDDEN);
    setPosition({500, 500});

}

void Menu::setPosition(const sf::Vector2f &position) {
    header.setPosition(position);
    Position::bottom(header, list);
}