//
// Created by Sneha Gurung on 12/5/22.
//

#ifndef SFML_HELPER_SCREEN_H
#define SFML_HELPER_SCREEN_H
#include <SFML/Graphics.hpp>
#include "ListItem.h"
#include "Fonts.h"


class Screen : public sf::Drawable, public States
{
private:
    sf::Text text;
    ListItem button;
    ListItem button2;
    sf::Text userInput;

public:
    Screen();
    Screen(std::string text, std::string buttonText, std::string buttonBack);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_HELPER_SCREEN_H
