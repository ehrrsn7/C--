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

Velocity Rock::randomizeVelocity() {
   // launch in random direction
   double randomAngle = random(0.0, M_PI * 2.0);
   Force initialForce = Vector::polar(ROCK_INIT_LAUNCH_FORCE, randomAngle); // N
   Acceleration initialAcceleration = initialForce / mass; // m/s/s
   double impulseTime = 1.0; // s
   return initialAcceleration * impulseTime;
}
