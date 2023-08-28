//
// Created by Sneha Gurung on 12/15/22.
//

#ifndef PORTFOLIO_DRAWCARD_H
#define PORTFOLIO_DRAWCARD_H
#include <SFML/Graphics.hpp>
#include <string>
#include "suitEnums.h"
#include "rankEnums.h"

class DrawCard {
public:
    DrawCard();
    static void runDrawCard();
};

class Card : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape _background;
    sf::Text rank_card;
    sf::Text rank2_card;
    sf::Sprite suit_card;
    static sf::Texture texture_card;
    static sf::Texture blueCard;
    static sf::Font font_card;
    suitEnums suits_card;
    rankEnum ranks_card;
    std::string rankToString();
    std::string suitToString();
    void initialize();
    void setUpBackground();
    void setUpRank();
    void setUpSuit();
public:
    Card();
    Card(std::string suit, std::string rank);
    Card(suitEnums suit, rankEnum rank);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setFillColor(const sf::Color& color);
    void setSize(sf::Vector2f size);
    void setSize(float width, float height);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
    void flip();
};

#endif //PORTFOLIO_DRAWCARD_H
