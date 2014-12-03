//
//  display.cpp
//  TME_1_2DGraphics
//
//  Created by Mel Mirasol on 2014-11-28.
//  Copyright (c) 2014 Mel Mirasol. All rights reserved.
//

#include "display.h"
#include <iostream>

Display::Display(int width, int height, const std::string& title) {
    std::cout << "Constructor" << std::endl;
}

Display::~Display() {
    std::cout << "Destructor" << std::endl;
}