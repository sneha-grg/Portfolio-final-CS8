//
// Created by Sneha Gurung on 12/1/22.
//

#ifndef SFML_HELPER_IMAGES_H
#define SFML_HELPER_IMAGES_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include "ImageEnum.h"

class Images : public sf::Drawable
{
private:
    static std::map<ImageEnum, sf::Texture> ImgObj;
    static void load(ImageEnum image);
    static std::string getPath(ImageEnum image);

public:
    static sf::Texture get(ImageEnum image);

};


#endif //SFML_HELPER_IMAGES_H
