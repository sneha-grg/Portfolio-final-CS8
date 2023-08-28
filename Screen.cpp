//
// Created by Sneha Gurung on 12/5/22.
//

#include "Screen.h"
#include "Position.h"

Screen::Screen() : Screen("", "", "")
{}

Screen::Screen(std::string text, std::string buttonText, std::string buttonBack)
: text(text, Fonts::getFont(OPEN_SANS), 50), button(buttonText, {300, 100}),
    button2(buttonBack, {300, 100})
{
    sf::RectangleShape r({1800, 2000});
    Position::centerText(r, this->text);
    Position::left(this->text, button2, 400.f);
    Position::right(this->text, button, 400.f);
}

void Screen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text);
    target.draw(button);
    target.draw(button2);
}
