//
//  rocks.cpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/14/20.
//

#include "rocks.hpp"
#include "physics-components/physicsFormulas.hpp"

void Rock::initializeRotation() {
    setRotation(random(ROCK_ROTATE_SPEED/2, ROCK_ROTATE_SPEED));
}

// TODO: change these from being hard coded values to variables
void Rock::initializePosition() {
   getPosition().setX(random(-500.0, 500.0));
   getPosition().setY(random(-500.0, 500.0));
}

void Rock::initializePosition(Position pInit) {
   setPosition(pInit);
}

void Rock::initializeVelocity() {
   std::cout << "Rock::initializeVelocity()\n";
   // launch in random direction
   auto initialForce = Force(ROCK_INIT_LAUNCH_FORCE, rad(random(0, 360)));
   auto initialAcceleration = initialForce / getMass();
   auto impulseTime = 1;
   setVelocity(getVelocity() + (initialAcceleration * impulseTime));
}

void Rock::initializeVelocity(Velocity vInit) {
   std::cout << "Rock::initializeVelocity(Velocity vInit) called.\n";

   // if non-default velocity, add it to our current v
   if (abs(getVelocity().getMagnitude()) > 0)
   {
      setVelocity(vInit);
      return;
   }
   
   // if default velocity, launch in random direction
   initializeVelocity(); // call initializeVelocity() to do this
}
