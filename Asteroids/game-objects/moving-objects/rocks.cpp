//
//  rocks.cpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/14/20.
//

#include "rocks.hpp"

#ifdef __APPLE__
#include "physicsFormulas.hpp"
#endif
#ifdef _WIN32
#include "physics-components/physicsFormulas.hpp"
#endif

void Rock::initializeRotation() {
    setRotation(random(ROCK_ROTATE_SPEED/2, ROCK_ROTATE_SPEED));
}

// TODO: change these from being hard coded values to variables
void Rock::initializePosition() {
   getPosition().setX(random(-500.0, 500.0));
   getPosition().setY(random(-500.0, 500.0));
}

void Rock::initializeVelocity() {
   std::cout << "Rock::initializeVelocity()\n";
   // launch in random direction
   auto initialForce = Force(Vector().polar(ROCK_INIT_LAUNCH_FORCE, rad(random(0, 360))));
   auto initialAcceleration = initialForce / getMass();
   auto impulseTime = 1;
   std::cout << "initialForce - " << initialForce
       << " initialAcceleration - " << initialAcceleration
       << " impulseTime - " << impulseTime
       << " dv result - " << initialAcceleration * impulseTime
       << std::endl;
   v += initialAcceleration * impulseTime;
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
