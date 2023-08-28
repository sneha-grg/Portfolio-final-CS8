//
// Created by Sneha Gurung on 12/13/22.
//

#ifndef PORTFOLIO_GREENBALL_H
#define PORTFOLIO_GREENBALL_H
#include <SFML/Graphics.hpp>


class GreenBall : sf::Drawable, sf::Transformable
{
private:
    sf::CircleShape circle;


public:
    GreenBall();
    void runGreenBall();
    void runGreenBall(sf::RenderWindow& window);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    //void runPong(sf::FloatRect Pong);

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_GREENBALL_H
