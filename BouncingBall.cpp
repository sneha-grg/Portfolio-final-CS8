//
// Created by Sneha Gurung on 10/7/22.
//

#include "BouncingBall.h"

void BouncingBall::runBouncingBall() {
    sf::RenderWindow window({800, 600, 32}, "Bouncing Ball");
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Blue);

    float x_vel = 0.1;
    float y_vel = 0.1;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                window.close();
            }
        }
        bounce(window.getSize(), circle, x_vel, y_vel);
        window.clear();
        window.draw(circle);
        window.display();
    }
}

void BouncingBall::bounce(sf::Vector2u size_window, sf::CircleShape &circle, float &x_vel, float &y_vel)
{
    if(circle.getPosition().x > size_window.x - 2*circle.getRadius())
    {
        x_vel = -0.1;
    }
    else if(circle.getPosition().x < 0)
    {
        x_vel = 0.1;
    }
    if(circle.getPosition().y > size_window.y - 2*circle.getRadius())
    {
        y_vel = -0.1;
    }
    else if(circle.getPosition().y < 0)
    {
        y_vel = 0.1;
    }
    circle.move(x_vel, y_vel);
}