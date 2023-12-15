//
//  movingObject.cpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/7/20.
//

#include "movingObject.hpp"

void MovingObject::displayDebugUpdateInfo() {
    std::cout << name << ".update() :: "
       << "p.add(v)"
       << "\t// v: " << v
       << "\t// p: " << p
       << "   ";
}

void MovingObject::setDeathTimer(double duration) {
    timer = duration;
    timerOn = true;
}

void MovingObject::accelerate() {
    if (!alive) return; // quick exit

    // std::cout << name
    //     << ".accelerate(v"
    //     << Velocity(v.forward(rotation) * thrust)
    //     << ") called.\n";

    v += Acceleration::forward(rotation) * thrust;
}

void MovingObject::hit() {
    setAlive(false);
    std::cout << name << ".hit() " << std::endl;
}
