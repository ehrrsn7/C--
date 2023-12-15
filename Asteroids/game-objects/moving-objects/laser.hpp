//
//  laser.hpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/8/20.
//

#pragma once

#include <iostream>
#include "movingObject.hpp"
#include "physics-components/vector.hpp"
#include "ui/uiDraw.hpp"

#define FIRE_DELAY_TIME .05 // laser firing rate delay in seconds
#define LASER_SPEED 10 // speed in pixels/frame
#define LASER_DEATH_TIME 20 // laser expiration time in seconds / 4
#define LASER_MASS 5 // kg

#define ALIVE true
#define DEAD false

class Laser : public MovingObject {
public:
   Laser(double firingAngle, Position shipPoint, Velocity shipVelocity, double shipRadius)
   {
      setName("Laser");
      setGameObjectID(laser);
      setPosition(Position(
         shipPoint + // initialize at ship's position
         Velocity::forward(firingAngle) * shipRadius * 6 // offset to front of ship
      ));
      setVelocity(Velocity::forward(firingAngle) * LASER_SPEED); // fire!!
      setDeathTimer(LASER_DEATH_TIME); // set to expire after desired amount (LASER_DEATH_TIME)
    }

    void display() override { drawDot(getPosition()); }
};
