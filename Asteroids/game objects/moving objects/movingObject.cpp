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
    // std::cout << "Laser death timer set to " << duration << std::endl; // debug
}

void MovingObject::accelerate() {
    if (!alive) return; // quick exit
    std::cout << name << ".accelerate(v";
    std::cout << Velocity(v.forward(rotation) * thrust) << ") called.\n";
    v.add(v.forward(rotation) * thrust);
}

void MovingObject::hit() {
    setAlive(false);
    std::cout << name << ".hit() " << std::endl;
}
