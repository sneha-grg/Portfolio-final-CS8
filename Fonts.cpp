//
// Created by Sneha Gurung on 11/22/22.
//
#include "Fonts.h"

std::map<fontsEnum, sf::Font> Fonts::map;

void Fonts::load(fontsEnum font)
{
    map[font].loadFromFile(getPath(font));
}

std::string Fonts::getPath(fontsEnum font) {
    switch (font)
    {
        case OPEN_SANS: return "fonts/Sans-Bold copy.ttf";
        case LAST_FONT:
            break;
    }

}

sf::Font &Fonts::getFont(fontsEnum font) {
    load(font);
    return map[font];
}
