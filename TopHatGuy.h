//
// Created by Sneha Gurung on 12/15/22.
//

#ifndef PORTFOLIO_TOPHATGUY_H
#define PORTFOLIO_TOPHATGUY_H
#include <SFML/Graphics.hpp>


class TopHatGuy {
public:
    TopHatGuy();
    void runTopHatGuy();
};

class TophatGuy : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape top, brim;
    sf::CircleShape face, beard;
    float movement_speed = 5;

public:
    TophatGuy();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void set_position(sf::Vector2f pos);
    void setPosition(float x, float y);
    void position_holder();
    void color_holder();
    void setters();
    void move();
};

#endif //PORTFOLIO_TOPHATGUY_H
