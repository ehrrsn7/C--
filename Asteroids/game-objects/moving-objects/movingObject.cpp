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
   if (!isAlive()) return; // quick exit
   v += Acceleration::forward(rotation) * thrust * ui.frameRate();
}

void MovingObject::hit() {
   setAlive(false);
   std::cout << name << ".hit() " << std::endl;
}

void MovingObject::updateTimer() {
   if (!timerOn) return;
   if (timer > 0) timer -= ui.frameRate();
   if (timer <= 0) hit();
}

void MovingObject::updateRotation() {
   // update orientation angle ('rotation')
   rotation += dr * abs(ui.frameRate());
   if (rotation < 0) rotation = M_PI * 2;
   else if (rotation > M_PI * 2) rotation = 0;
}

void MovingObject::updatePosition() {
   p += v * abs(ui.frameRate());
}
