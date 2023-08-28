//
// Created by Sneha Gurung on 12/1/22.
//

#include "ListItem.h"
#include "Position.h"
#include "Fonts.h"
#include "MouseEvents.h"


void ListItem::setUpText(std::string text) {
    this->text.setFont(Fonts::getFont(OPEN_SANS));
    this->text.setString(text);
    this->text.setFillColor(sf::Color(66, 135, 78));
    Position::centerText(box, this->text);

}

void ListItem::setUpBox(sf::Vector2f size) {
    setBoxSize(size);

}

ListItem::ListItem() : ListItem("", {0.f, 0.f}) {

}

ListItem::ListItem(std::string text, sf::Vector2f size) {
    setUpText(text);
    setUpBox(size);
}

void ListItem::oneClick(void (*f)(), sf::RenderWindow &window) {
    if(MouseEvents::isClicked(box, window)) {
        f();
    }
}

void ListItem::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(MouseEvents::isHovered(box,window)){
        box.setFillColor(hoverColor);
        text.setFillColor(backgroundColor);
    }
    else
    {
        box.setFillColor(backgroundColor);
        text.setFillColor(hoverColor);

    }
}

void ListItem::update() {

}

void ListItem::setBoxSize(sf::Vector2f size) {
    box.setSize(size);
    Position::centerText(box, this->text);

}

void ListItem::setTextSize(unsigned int size) {
    text.setCharacterSize(size);
    Position::centerText(box,this->text);
}

void ListItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!checkState(HIDDEN)) {
        target.draw(box);
        target.draw(text);
    }
}

sf::FloatRect ListItem::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void ListItem::setPosition(sf::Vector2f position) {
    box.setPosition(position);
    Position::centerText(box, text);
}

void ListItem::setString(std::string text) {
    this->text.setString(text);
}

void ListItem::setPosition(float x, float y ) {
    setPosition({x,y});
}

std::string ListItem::getString() {
    return text.getString();
}
