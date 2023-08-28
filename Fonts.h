//
// Created by Sneha Gurung on 11/22/22.
//

#ifndef SFML_HELPER_FONTS_H
#define SFML_HELPER_FONTS_H
#include "fontsEnum.h"
#include <SFML/Graphics.hpp>
#include <map>


class Fonts {
private:
    static std::map<fontsEnum, sf::Font> map;
    static void load(fontsEnum font);
    static std::string getPath(fontsEnum font);

public:
    static sf::Font& getFont(fontsEnum font);

};


#endif //SFML_HELPER_FONTS_H
