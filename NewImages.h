//
// Created by Sneha Gurung on 12/14/22.
//

#ifndef PORTFOLIO_NEWIMAGES_H
#define PORTFOLIO_NEWIMAGES_H
#include <SFML/Graphics.hpp>
#include "ImageEnum.h"
#include "Images.h"


class NewImages : public sf::Drawable, public sf::Transformable
{
public:
    sf::Sprite GameImage;
    ImageEnum _image;
    static sf::Texture texture;
    int value;

public:
    // CIRCLE, BALL, PONG, GUY, CARD, POKER, SNAKE
    static sf::Texture green_circle;
    static sf::Texture bouncing_ball;
    static sf::Texture pong_game;
    static sf::Texture top_hat_guy;
    static sf::Texture draw_card;
    static sf::Texture poker_ays;
    static sf::Texture snake_final;

public:
    NewImages();
    explicit NewImages(int value);
    ImageEnum getProject(int value);
    void setProjImage(int value);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //PORTFOLIO_NEWIMAGES_H
