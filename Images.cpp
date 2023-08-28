//
// Created by Sneha Gurung on 12/1/22.
//

#include "Images.h"

std::map<ImageEnum, sf::Texture> Images::ImgObj;

void Images::load(ImageEnum image)
{
    if(!ImgObj[image].loadFromFile(getPath(image)))
        exit(65);
}

std::string Images::getPath(ImageEnum image)
{
    switch(image)
    {
        case CIRCLE: return "Images/circle.png";
        case BALL: return "Images/greenBall.png";
        case PONG: return "Images/pong.png";
        case GUY: return "Images/guy.png";
        case CARD: return "Images/card.png";
        case POKER: return "Images/poker.png";
        case SNAKE: return "Images/snake.png";
        case LAST_IMAGE: "";
    }
    return std::string();
}

sf::Texture Images::get(ImageEnum image)
{
    load(image);
    return ImgObj.at(image);
}
