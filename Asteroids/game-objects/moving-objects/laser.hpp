//
//  laser.hpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/8/20.
//

#pragma once

#include <iostream>
#include "movingObject.hpp"

#ifdef __APPLE__
#include "vector.hpp"
#include "uiDraw.hpp"
#endif
#ifdef _WIN32
#include "physics-components/vector.hpp"
#include "ui/uiDraw"
#endif

#define FIRE_DELAY_TIME .1 // laser firing rate delay in seconds
#define LASER_SPEED 100 // speed in pixels/frame
#define LASER_DEATH_TIME 2 // laser expiration time in seconds
#define LASER_MASS 5 // kg

#define ALIVE true
#define DEAD false

class Ship; // forward declaration

class Laser : public MovingObject {
private:
   Velocity launchVelocity(double firingAngle);
   
   // private constructor used by Laser::Laser(const Interface&, const Ship*)
   Laser(const Interface & ui) : MovingObject(ui) {
      // set default parent properties
      name = "Laser";
      gameObjectID = laser;
      setDeathTimer(LASER_DEATH_TIME); // sets timerOn to true
   }
   
public:
   Laser(const Interface & ui, const Ship * ship);

   void display() override { drawDot(getPosition()); }
   
   // assignment operator '='
   Laser & operator = (const Laser & rhs);
};
