//
// Created by Sneha Gurung on 12/13/22.
//

#include "Window.h"

Window::Window() {
    window.create(sf::VideoMode{1800, 1300, 32}, "Portfolio");
    window.setFramerateLimit(60);
    line();
}

void Window::slideProj(sf::RenderWindow &window, const int iterImage) {
    this->setProjImage(iterImage);
}

void Window::run() {

    for (int i = 0; i < 7; i++) {
        next.emplace_back(menu[i], "PRESS RIGHT", "PRESS LEFT");
    }

    int iterImage = 1;
    auto iterNext = next.begin();
    slideProj(window, iterImage);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                if (iterNext != next.begin()) {
                    --iterNext;
                    iterImage--;
                    slideProj(window, iterImage);
                }
            }

            isKEYPressed();

            if(mainMenu)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                    if (iterNext != next.end() - 1) {
                        ++iterNext;
                        ++iterImage;
                        slideProj(window, iterImage);
                    }
                }
            }
        }

        window.clear(sf::Color(181, 139, 160));
        if(mainMenu)
        {
            window.draw(lines);
            window.draw(GameImage);
            window.draw(*iterNext);
        }
        else if(showGreenBall)
            ////window draw green greenBall
            greenBall.runGreenBall();

        else if (showBouncingBall)
            bouncingBall.runBouncingBall();

        else if (showPongBall)
            pongGame.runPongGame();

        else if (showTopHatGuy)
            hatGuy.runTopHatGuy();

        else if (showDrawCard)
            drawCard.runDrawCard();

        else if (showPokerTable)
            poker_analysis.runPokerGame();

        else if (showSnakeGame)
            snakeGame.runSnakeGame();

        window.display();
    }

    displayImage.clear();
}

void Window::line() {
    lines.setFillColor(sf::Color::Black);
    lines.setSize({1800,10});
    lines.setPosition({0, 1100});
}

void Window::isKEYPressed() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        showGreenBall = true;
        mainMenu = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        showBouncingBall = true;
        mainMenu = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        showPongBall = true;
        mainMenu = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        showTopHatGuy = true;
        mainMenu = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        showDrawCard = true;
        mainMenu = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        showPokerTable = true;
        mainMenu = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        showSnakeGame = true;
        mainMenu = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
    {
        showGreenBall = false;
        showBouncingBall = false;
        showPongBall = false;
        showTopHatGuy = false;
        showDrawCard = false;
        showPokerTable = false;
        showSnakeGame = false;
        mainMenu = true;
    }
}

