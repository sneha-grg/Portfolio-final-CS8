//
// Created by Sneha Gurung on 12/14/22.
//

#include "NewImages.h"

sf::Texture NewImages::texture;
sf::Texture NewImages::green_circle;
sf::Texture NewImages::bouncing_ball;
sf::Texture NewImages::pong_game;
sf::Texture NewImages::top_hat_guy;
sf::Texture NewImages::draw_card;
sf::Texture NewImages::poker_ays;
sf::Texture NewImages::snake_final;

NewImages::NewImages() : NewImages(0)
{
    getProject(0);
}

NewImages::NewImages(int value) : value(value)
{
    getProject(this->value);
}


//std::string NewImages::imagesToString(int value) {
//    _image = static_cast<ImageEnum>(value);
//    switch(_image)
//    {
//        case CIRCLE: return "Images/circle.png";
//        case BALL: return "Images/greenBall.png";
//        case PONG: return "Images/pong.png";
//        case GUY: return "Images/guy.png";
//        case CARD: return "Images/card.png";
//        case POKER: return "Images/poker.png";
//        case SNAKE: return "Images/snake.png";
//        case LAST_IMAGE: "";
//    }
//}

void NewImages::setProjImage(const int value) {
    switch (value) {
        case 1:
            green_circle.loadFromFile("Images/circle.png");
            GameImage.setTexture(green_circle);
            GameImage.setPosition({600, 200});
            break;
        case 2: bouncing_ball.loadFromFile("Images/ball.png");
            GameImage.setTexture(bouncing_ball);
            GameImage.setPosition({550, 200});
            break;
        case 3: pong_game.loadFromFile("Images/pong.png");
            GameImage.setTexture(pong_game);
            GameImage.setPosition({600, 200});
            break;
        case 4: top_hat_guy.loadFromFile("Images/guy.png");
            GameImage.setTexture(top_hat_guy);
            GameImage.setPosition({600, 200});
            break;
        case 5: draw_card.loadFromFile("Images/card.png");
            GameImage.setTexture(draw_card);
            GameImage.setPosition({600, 200});
            break;
        case 6:
            GameImage.setPosition({600, 200});
            poker_ays.loadFromFile("Images/poker.png");
            GameImage.setTexture(poker_ays);
            break;
        case 7: snake_final.loadFromFile("Images/snake.png");
            GameImage.setTexture(snake_final);
            GameImage.setPosition({600, 200});
            break;
    }
}

ImageEnum NewImages::getProject(const int value) {
    switch(value)
    {
        case 1: return ImageEnum::CIRCLE;
        case 2: return ImageEnum::BALL;
        case 3: return ImageEnum::PONG;
        case 4: return ImageEnum::GUY;
        case 5: return ImageEnum::CARD;
        case 6: return ImageEnum::POKER;
        case 7: return ImageEnum::SNAKE;
        default: return LAST_IMAGE;
    }
}

void NewImages::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(GameImage);
}


