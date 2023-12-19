//
//  movingObject.cpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/7/20.
//

#include "movingObject.hpp"

void MovingObject::setDeathTimer(double duration) {
    timer = duration;
    timerOn = true;
}

void MovingObject::accelerate() {
    if (!alive) return; // quick exit

    v += Acceleration::forward(rotation) * thrust * ui.frameRate();
}

void MovingObject::hit() {
    setAlive(false);
    std::cout << name << ".hit() " << std::endl;
}
