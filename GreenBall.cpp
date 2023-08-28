//
// Created by Sneha Gurung on 12/13/22.
//

#include "GreenBall.h"
#include "MouseEvents.h"

GreenBall::GreenBall() = default;

void GreenBall::runGreenBall() {
    sf::RenderWindow window(sf::VideoMode{600,600, 32},
                            "Green Circle!");
    sf::CircleShape circle(300.f);
    circle.setFillColor(sf::Color(81, 135, 61));

    while(window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
        }

        window.draw(circle);
        window.display();
    }
}

void GreenBall::runGreenBall(sf::RenderWindow &window) {
    circle.setFillColor(sf::Color::Green);
    circle.setRadius(250.f);

    window.draw(circle);
}

void GreenBall::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents::isClicked(circle, window))
    {
        circle.setFillColor(sf::Color::Blue) ;
    }
}

void GreenBall::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
