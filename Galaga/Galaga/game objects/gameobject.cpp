//
//  gameobject.cpp
//  Galaga
//
//  Created by Elijah Harrison on 12/20/21.
//

#include "gameobject.hpp"

void Gameobject::updateOrientationAngle() {
    
    angle += da / 60.0; // fps
    if (angle < 0) angle = M_PI*2;
    else if (angle > M_PI*2) angle = 0;
    
}

void Gameobject::setScreenVars(Vec2 tl, Vec2 br) {
    Gameobject::screenTL.set(tl);
    Gameobject::screenBR.set(br);
}

void Gameobject::setFPS(float fps) {
    Gameobject::FPS = fps;
}

// set static vars
Vec2 Gameobject::screenBR = Vec2();
Vec2 Gameobject::screenTL = Vec2();
int Gameobject::FPS = 60;
