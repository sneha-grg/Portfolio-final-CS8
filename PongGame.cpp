//
// Created by Sneha Gurung on 12/15/22.
//

#include "PongGame.h"

PongGame::PongGame() = default;

void PongGame::runPongGame() {
    sf::RenderWindow window({1000, 600, 32}, "Pong Game");
    Ball ball;
    ball.setVelocity({0.1, 0.1});

    Paddle paddle_one;
    Paddle paddle_two;

    sf::CircleShape a;

    while(window.isOpen())
    {
        sf::Event event{};
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                window.close();
            }
        }

        ball.bounce(window.getSize());
        paddle_one.update(window.getSize());
        paddle_two.update2(window.getSize());

        ball.isColliding(paddle_one);
        ball.isColliding(paddle_two);

        window.clear(sf::Color( 255, 182, 193));
        window.draw(ball);
        window.draw(paddle_one);
        window.draw(paddle_two);
        window.display();
    }
}

Ball::Ball()
{
    setRadius(50);
    setFillColor(sf::Color(66, 135, 245));
    setPosition(400, 200);
}


void Ball::bounce(const sf::Vector2u &window_size)
{
    sf::FloatRect b = getGlobalBounds();
    if(b.top + b.height >= window_size.y || b.top <= 0)
    {
        velocity.y = -velocity.y;
    }
    if(b.left + b.width >= window_size.x || b.left <= 0)
    {
        reset();
    }

    sf::CircleShape::move(velocity);
}


void Ball::setVelocity(const sf::Vector2f &velocity)
{
    this->velocity = velocity;
}

void Ball::reset() {
    setPosition(400, 200);
}

void Ball::isColliding(const Paddle &paddle) {
    sf::FloatRect ball = getGlobalBounds();
    sf::FloatRect pad = paddle.getGlobalBounds();
    if (ball.intersects(pad))
        velocity.x = - velocity.x;
}

Paddle::Paddle() : sf::RectangleShape()
{
    setFillColor(sf::Color::Black);
    setSize({30, 150});
}

void Paddle::set_Position(float x_pos, float y_pos)
{
    sf::RectangleShape::setPosition(x_pos, y_pos);
}

void Paddle::updateInput(const sf::Vector2u &window_size)
{
    sf::FloatRect gb = getGlobalBounds();
    if(gb.top >= window_size.y || gb.top <= 0) { set_Position(x_bound_1, 0); }
    if (gb.top + gb.height >= window_size.y) { set_Position(x_bound_1, y_bound); }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        move({0.f, -movement_speed});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        move({0.f, movement_speed});
    }
}

void Paddle::updateInput_two(const sf::Vector2u &window_size)
{
    sf::FloatRect GB = getGlobalBounds();
    if(GB.top >= window_size.y || GB.top <= 0) { set_Position(x_bound, 0); }
    if (GB.top + GB.height >= window_size.y) { set_Position(x_bound, y_bound); }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        move({0.f, -movement_speed});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        move({0.f, movement_speed});
    }
}

void Paddle::update(const sf::Vector2u &window_size)
{
    this->updateInput({window_size.x, window_size.y});
}

void Paddle::update2(const sf::Vector2u &window_size)
{
    this->updateInput_two({window_size.x, window_size.y});
}

