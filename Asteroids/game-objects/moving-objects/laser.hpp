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
#define LASER_SPEED 10 // speed in pixels/frame
#define LASER_DEATH_TIME 20 // laser expiration time in seconds / 4
#define LASER_MASS 5 // kg

#define ALIVE true
#define DEAD false

class Laser : public MovingObject {
private:
   Position offsetToShipPosition(double firingAngle, const Position &shipPoint, double shipRadius) {
      double offsetAmount = shipRadius * 6;
      return Position(
         // initialize at ship's position
         shipPoint +
         // offset to front of ship
         Position(Vector::forward(firingAngle)) * offsetAmount
      );
   }
   
   Velocity launch(double firingAngle) {
      return Velocity::forward(firingAngle * LASER_SPEED);
   }
   
public:
   Laser(const Interface & ui, double firingAngle, Position shipPoint, Velocity shipVelocity, double shipRadius)
      : MovingObject(ui)
   {
      // set parent properties
      name = "Laser";
      gameObjectID = laser;
      p = offsetToShipPosition(firingAngle, shipPoint, shipRadius);
      v = launch(firingAngle); // fire!!
      setDeathTimer(LASER_DEATH_TIME); // sets timerOn to true
   }

   void display() override { drawDot(getPosition()); }
   
   // assignment operator '='
   Laser & operator = (const Laser & rhs) {
      p = rhs.p;
      v = rhs.v;
      setDeathTimer(rhs.timer); // sets timerOn to true
      return *this;
   }
};
