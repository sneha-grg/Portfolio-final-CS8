//
// Created by Sneha Gurung on 12/15/22.
//

#ifndef PORTFOLIO_PONGGAME_H
#define PORTFOLIO_PONGGAME_H
#include <SFML/Graphics.hpp>


class PongGame {
public:
    PongGame();
    void runPongGame();

};


class Paddle : public sf::RectangleShape
{
private:
    float y_bound = 450, x_bound = 960, x_bound_1 = 10;
    // 750, 450 ... 1000, 600
    float movement_speed = 0.1;

public:
    Paddle();
    void set_Position(float x_pos, float y_pos);
    void updateInput(const sf::Vector2u &window_size);
    void update(const sf::Vector2u &window_size);
    void updateInput_two(const sf::Vector2u &window_size);
    void update2(const sf::Vector2u &window_size);
};

class Ball : public sf::CircleShape
{
private:
    sf::Vector2f velocity = {0.2, 0.2};

public:
    Ball();
    void bounce(const sf::Vector2u &window_size);
    void setVelocity(const sf::Vector2f &velocity);
    void isColliding(const Paddle &paddle);
    void reset();
};


#endif //PORTFOLIO_PONGGAME_H
