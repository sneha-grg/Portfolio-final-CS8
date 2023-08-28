//
// Created by Sneha Gurung on 12/14/22.
//

#ifndef PORTFOLIO_IMAGEDISPLAY_H
#define PORTFOLIO_IMAGEDISPLAY_H
#include <SFML/Graphics.hpp>
#include "NewImages.h"


class ImageDisplay {
private:
    std::vector<NewImages> imageDisplay;

public:
    ImageDisplay();
    void add_image(const NewImages& newImages);
};


#endif //PORTFOLIO_IMAGEDISPLAY_H
