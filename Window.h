//
// Created by Sneha Gurung on 12/13/22.
//

#ifndef PORTFOLIO_WINDOW_H
#define PORTFOLIO_WINDOW_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Screen.h"
#include "Menu.h"
#include "GreenBall.h"
#include "BouncingBall.h"
#include "PongGame.h"
#include "TopHatGuy.h"
#include "DrawCard.h"
#include "PokerGame.h"
#include "SnakeFinalGame.h"

#include "NewImages.h"
#include "ImageEnum.h"
#include "ImageDisplay.h"
#include "Images.h"
#include "MouseEvents.h"


class Window : public NewImages {
private:
    sf::RenderWindow window;
    sf::RectangleShape lines;
    sf::RectangleShape button1;
    std::vector<Screen> next;
    std::vector<std::string> menu = {"Green Circle", "Bouncing Ball", "Pong", "Top Hat Guy",
                                     "Draw pokerCard", "Poker", "Snake-Final Game"};

    NewImages ImgObj;

    std::vector<NewImages> displayImage;
    GreenBall greenBall;
    BouncingBall bouncingBall;
    PongGame pongGame;
    TopHatGuy hatGuy;
    DrawCard drawCard;
    PokerGame poker_analysis;
    SnakeFinalGame snakeGame;

    bool showGreenBall = false;
    bool showBouncingBall = false;
    bool showPongBall = false;
    bool showTopHatGuy = false;
    bool showDrawCard = false;
    bool showPokerTable = false;
    bool showSnakeGame = false;
    bool mainMenu = true;


public:
    Window();
    void slideProj(sf::RenderWindow& window, int iterImage);
    void isKEYPressed();
    void run();
    void line();

};


#endif //PORTFOLIO_WINDOW_H
