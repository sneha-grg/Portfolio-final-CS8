//
// Created by Sneha Gurung on 10/7/22.
//

#ifndef BOUNCING_BALL_BOUNCINGBALL_H
#define BOUNCING_BALL_BOUNCINGBALL_H
#include <iostream>
#include <SFML/Graphics.hpp>

class BouncingBall{
public:
    void runBouncingBall();
    void bounce(sf::Vector2u size_window, sf::CircleShape &circle, float &x_vel, float &y_vel);
};

#endif //BOUNCING_BALL_BOUNCINGBALL_H
