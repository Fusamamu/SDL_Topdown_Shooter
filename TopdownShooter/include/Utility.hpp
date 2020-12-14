//
//  Utility.hpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra on 6/12/2563 BE.
//

#ifndef Utility_hpp
#define Utility_hpp

#include <stdio.h>

struct Point{
    float x;
    float y;
//    Point(float xx, float yy){
//        x = xx;
//        y = yy;
//    }
};

struct __Color{
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color black = {0, 0, 0, 255};
};

#endif /* Utility_hpp */
