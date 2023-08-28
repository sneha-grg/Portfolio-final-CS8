//
// Created by Sneha Gurung on 12/15/22.
//

#include "TopHatGuy.h"

TopHatGuy::TopHatGuy() = default;

void TopHatGuy::runTopHatGuy() {
    sf::RenderWindow window({800, 600, 32}, "Top Hat Guy");
    window.setFramerateLimit(60);
    TophatGuy guy;
    guy.set_position({600, 100});

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

        window.clear(sf::Color(199, 121, 121));
        guy.move();
        window.draw(guy);
        window.display();
    }
}

TophatGuy::TophatGuy()
{
    setters();
    position_holder();
    color_holder();
}

void TophatGuy::setters() {
    top.setSize({50, 70});
    brim.setSize({80, 25});
    face.setRadius(30);
    beard.setRadius(30);
    beard.setPointCount(3);
}

void TophatGuy::position_holder() {
    top.setPosition({0,0});
    brim.setPosition({top.getGlobalBounds().left / 2 - top.getGlobalBounds().width / 3,
                      top.getGlobalBounds().top + top.getGlobalBounds().height});
    face.setPosition({top.getGlobalBounds().left - top.getGlobalBounds().width / 10,
                      top.getGlobalBounds().top + top.getGlobalBounds().height});
    beard.setPosition({top.getGlobalBounds().left + top.getGlobalBounds().width + 5,
                       top.getGlobalBounds().top + top.getGlobalBounds().height + 2*
                                                                                  top.getSize().x});
    beard.rotate(180);
}

void TophatGuy::color_holder() {
    top.setFillColor(sf::Color(92, 73, 62));
    brim.setFillColor(sf::Color::Black);
    face.setFillColor(sf::Color(176, 157, 102));
    beard.setFillColor(sf::Color(92, 73, 62));
}

void TophatGuy::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    states.transform = getTransform();
    window.draw(face, states);
    window.draw(top, states);
    window.draw(brim, states);
    window.draw(beard, states);
}

void TophatGuy::set_position(sf::Vector2f pos)
{
    sf::Transformable::setPosition(pos);
    // calling parent func. requires calling transformable
}

void TophatGuy::setPosition(float x, float y)
{
    setPosition(x,y);
}

void TophatGuy::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        top.move({0, -movement_speed});
        brim.move({0, -movement_speed});
        face.move({0, -movement_speed});
        beard.move({0, -movement_speed});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        top.move({0, movement_speed});
        brim.move({0, movement_speed});
        face.move({0, movement_speed});
        beard.move({0, movement_speed});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        top.move({-movement_speed, 0});
        brim.move({-movement_speed, 0});
        face.move({-movement_speed, 0});
        beard.move({-movement_speed, 0});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        top.move({movement_speed, 0});
        brim.move({movement_speed, 0});
        face.move({movement_speed, 0});
        beard.move({movement_speed, 0});
    }
}
