//
// Created by Sneha Gurung on 12/15/22.
//

#include "SnakeFinalGame.h"

SnakeFinalGame::SnakeFinalGame() = default;

void SnakeFinalGame::runSnakeGame() {
    GameSnake snake;
    snake.start();
}

// CREATING THE SNAKE
SFMLSnake::SFMLSnake(sf::Vector2f pos) {
    snake_head.setSize({30, 30});
    snake_head.setFillColor(sf::Color(183, 194, 124));
    snake_head.setPosition(pos);
    snake_pos = pos;
}

sf::Vector2f SFMLSnake::getPosition() {
    return snake_pos;
}

void SFMLSnake::setPosition(sf::Vector2f new_pos) {
    snake_pos = new_pos;
}

sf::RectangleShape SFMLSnake::getShape() {
    return snake_head;
}

void SFMLSnake::updatePos() {
    snake_head.setPosition(snake_pos);
}

// CREATING THE APPLE
Apple::Apple() {
    apple.setSize({30, 30});
    apple.setFillColor(sf::Color(176, 73, 42));
    apple.setPosition({500, 500});

}

void Apple::setPos(sf::Vector2f new_pos) {
    apple.setPosition(new_pos);
}

sf::RectangleShape Apple::getApple() {
    return apple;
}

// MAIN ENGINE

GameSnake::GameSnake() {
    window.create(sf::VideoMode{1000, 800, 32}, "Snake");
    window.setFramerateLimit(60);
    velocity = 10;
    snake_dir = Direction::RIGHT;
    mainTime = sf::Time::Zero;
    createSnake();
    addBody = 0;
    placeApple();
}

void GameSnake::start() {
    // Main loop
    sf::Clock clock;
    while(window.isOpen())
    {
        sf::Event event{};
        // will restart clock and return the time clock ran
        sf::Time time = clock.restart();
        mainTime += time; // adds to let snake know when to move
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up)
                    addDir(Direction::UP);
                else if (event.key.code == sf::Keyboard::Down)
                    addDir(Direction::DOWN);
                else if (event.key.code == sf::Keyboard::Right)
                    addDir(Direction::RIGHT);
                else if (event.key.code == sf::Keyboard::Left)
                    addDir(Direction::LEFT);
            }
        }
        updateInput();
        window.clear(sf::Color(143, 118, 168));
        window.draw(apple.getApple());

        for (auto & s: snake) {
            window.draw(s.getShape());
        }
        window.display();
    }

}


void GameSnake::createSnake() {
    // creates a new snake at the beginning of each game
    snake.clear();
    snake.emplace_back(sf::Vector2f{100, 100});
    snake.emplace_back(sf::Vector2f{65, 100});
    snake.emplace_back(sf::Vector2f{30, 100});
}

void GameSnake::addSnakeBody() {
    // adds a new rect shape before the head
    sf::Vector2f new_snake_pos = snake[snake.size() - 1].getPosition();
    snake.emplace_back(new_snake_pos);
}

void GameSnake::updateInput() {
    // each rect shape's pos will be updated
    if (mainTime.asSeconds() >= sf::seconds(1.f / float(velocity)).asSeconds())
    {
        sf::Vector2f curr = snake[0].getPosition(); // pos of snake head
        sf::Vector2f lastPos = curr;

        checkDir();

        // incrementing body
        // decrementing allows the body to not create an infinite rect shape
        if (addBody) {
            addSnakeBody();
            addBody--;
        }

        // for the snake's head position
        switch (snake_dir) {
            case Direction::UP:
                snake[0].setPosition({curr.x, curr.y - 35});
                break;
            case Direction::DOWN:
                snake[0].setPosition({curr.x, curr.y + 35});
                break;
            case Direction::RIGHT:
                snake[0].setPosition({curr.x + 35, curr.y});
                break;
            case Direction::LEFT:
                snake[0].setPosition({curr.x - 35, curr.y});
                break;
        }

        // for snake tail position, like swapping func
        for (int i = 1; i < snake.size(); i++) {
            curr = snake[i].getPosition();
            snake[i].setPosition(lastPos);
            lastPos = curr;
        }

        // updates the snake's body
        for (auto & s: snake)
            s.updatePos();

        // TWO collisions
        SnakeAppleCol();
        SnakeSnakeCol();
        boundsCol(window.getSize());

        mainTime = sf::Time::Zero;
    }
}

void GameSnake::addDir(int newDir) {
    // updating the new direction through user input
    if (dirQueue.empty())
        dirQueue.emplace_back(newDir);
    else {
        if (dirQueue.back() != newDir) {
            dirQueue.emplace_back(newDir);
        }
    }
}


void GameSnake::placeApple() {
    // placing the apple a certain location
    // with bounds
    bool point;
    sf::Vector2f ApplePos;
    // seed rand generator
    srand(time(nullptr));
    do {
        point = false;
        ApplePos.x = rand()%(window.getSize().x / 35) * 30;
        ApplePos.y = rand()%(window.getSize().y / 35) * 30;

        for (auto & a: snake) {
            if (a.getShape().getGlobalBounds().intersects(sf::Rect<float>
                                                                  (ApplePos.x, ApplePos.y, 35, 35))) {
                point = true;
                break;
            }
        }
    } // run at least once, unless point is true, then loop starts again
    while (point);
    apple.setPos(ApplePos);
}


void GameSnake::SnakeAppleCol() {
    // As the snake eats apple, add a body and place apple in another location
    if (snake[0].getShape().getGlobalBounds().intersects(apple.getApple().getGlobalBounds()))
    {
        addBody += 1;
        placeApple();
    }
}

void GameSnake::SnakeSnakeCol() {
    // restarts game if the snake collides itself
    for (int i = 1; i < snake.size(); i++) {
        if (snake[0].getShape().getGlobalBounds().intersects(snake[i].getShape().getGlobalBounds()))
            createSnake();
    }
}

void GameSnake::boundsCol(const sf::Vector2u &window_size) {
    // restarts the game if the snake goes out of bounds
    sf::FloatRect b = snake[0].getShape().getGlobalBounds();
    if (b.top + b.height >= window_size.y || b.top <= 0)
        createSnake();
    if (b.left + b.width >= window_size.x || b.left <= 0)
        createSnake();
}

void GameSnake::checkDir() {
    if (!dirQueue.empty()) {
        switch (snake_dir) {
            case Direction::UP:
                if (dirQueue.front() != Direction::DOWN) {
                    snake_dir = dirQueue.front();
                }
                break;
            case Direction::DOWN:
                if (dirQueue.front() != Direction::UP) {
                    snake_dir = dirQueue.front();
                }
                break;
            case Direction::RIGHT:
                if (dirQueue.front() != Direction::LEFT) {
                    snake_dir = dirQueue.front();
                }
                break;
            case Direction::LEFT:
                if (dirQueue.front() != Direction::RIGHT) {
                    snake_dir = dirQueue.front();
                }
                break;
        }
        dirQueue.pop_front();
    }
}

