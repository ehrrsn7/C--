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
#endif
#ifdef _WIN32
#include "physics-components/vector.hpp"
#endif

#ifdef __APPLE__
#include "uiDraw.hpp"
#endif
#ifdef _WIN32
#include "ui/uiDraw.hpp"
#endif

#define FIRE_DELAY_TIME .05 // laser firing rate delay in seconds
#define LASER_SPEED 10 // speed in pixels/frame
#define LASER_DEATH_TIME 20 // laser expiration time in seconds / 4
#define LASER_MASS 5 // kg

#define ALIVE true
#define DEAD false

class Laser : public MovingObject {
public:
   Laser(const Interface & ui, double firingAngle, Position shipPoint, Velocity shipVelocity, double shipRadius)
      : MovingObject(ui)
   {
      // set parent properties
      setName("Laser");
      setGameObjectID(laser);
      p = Position(
         shipPoint + // initialize at ship's position
         Vector::forward(firingAngle) * shipRadius * 6 // offset to front of ship
      );
      setVelocity(Velocity::forward(firingAngle) * LASER_SPEED); // fire!!
      setDeathTimer(LASER_DEATH_TIME); // set to expire after desired amount (LASER_DEATH_TIME)
   }

   void display() override { drawDot(getPosition()); }
   
   // assignment operator '='
   Laser & operator = (const Laser & rhs) {
       setPosition(rhs.p);
       setVelocity(rhs.v);
       setDeathTimer(rhs.timer);
       return *this;
   }
};
