//
//  display.h
//  TME_1_2DGraphics
//
//  Created by Mel Mirasol on 2014-11-28.
//  Copyright (c) 2014 Mel Mirasol. All rights reserved.
//

#ifndef __TME_1_2DGraphics_1__display__
#define __TME_1_2DGraphics_1__display__

#include <string>

using namespace std;

class Display {
public:
    Display(int width, int height, const std::string& title);
    virtual ~Display();
protected:
private:
    Display(const Display& other) {}
};

#endif