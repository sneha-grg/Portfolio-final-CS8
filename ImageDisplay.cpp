//
// Created by Sneha Gurung on 12/14/22.
//

#include "ImageDisplay.h"

ImageDisplay::ImageDisplay() {}

void ImageDisplay::add_image(const NewImages &newImages) {
    imageDisplay.push_back(newImages);
}
