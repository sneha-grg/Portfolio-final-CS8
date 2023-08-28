//
// Created by Sneha Gurung on 12/15/22.
//

#ifndef PORTFOLIO_SNAKEFINALGAME_H
#define PORTFOLIO_SNAKEFINALGAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>


class SnakeFinalGame {
public:
    SnakeFinalGame();
    void runSnakeGame();

};

class SFMLSnake {
private:
    sf::RectangleShape snake_head;
    sf::Vector2f snake_pos;

public:
    SFMLSnake(sf::Vector2f pos);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f new_pos);
    sf::RectangleShape getShape();
    void updatePos();
};

class Apple {
private:
    sf::RectangleShape apple;

public:
    Apple();
    void setPos(sf::Vector2f new_pos);
    sf::RectangleShape getApple();
};

class GameSnake {
private:
    sf::RenderWindow window;
    std::vector<SFMLSnake> snake;
    sf::Time mainTime;
    std::deque<int> dirQueue;
    int snake_dir;
    int velocity;
    Apple apple;
    int addBody;

public:
    enum Direction {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };
    GameSnake();
    void start();
    void createSnake();
    void addSnakeBody();
    void placeApple();
    void updateInput();
    void addDir(int newDir);
    void checkDir();
    void SnakeAppleCol();
    void SnakeSnakeCol();
    void boundsCol(const sf::Vector2u &window_size);
};



#endif //PORTFOLIO_SNAKEFINALGAME_H
