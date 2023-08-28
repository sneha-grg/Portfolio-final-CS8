//
// Created by Sneha Gurung on 12/1/22.
//

#ifndef SFML_HELPER_LISTITEM_H
#define SFML_HELPER_LISTITEM_H
#include <SFML/Graphics.hpp>
#include "States.h"


class ListItem : public sf::Drawable, public States {
private:
    sf::RectangleShape box;
    sf::Text text;
    void setUpText(std::string text);


private:
    void setUpBox(sf::Vector2f size);
    sf::Color backgroundColor  = sf::Color::White, hoverColor  = sf::Color::Blue;

public:
    ListItem();
    ListItem(std::string text, sf::Vector2f size);
    void oneClick(void (*f)(), sf::RenderWindow &window);
    void eventHandler(sf::RenderWindow& window, const sf::Event& event);
    void update();
    void setBoxSize(sf::Vector2f size);
    void setTextSize(unsigned int size);
    sf::FloatRect getGlobalBounds() const;
    void setPosition(sf::Vector2f position);
    void setString(std::string text);
    std::string getString();

    void setPosition(float x, float y);



    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_HELPER_LISTITEM_H
