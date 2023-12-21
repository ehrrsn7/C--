//
//  laser.cpp
//  Asteroids
//
//  Created by Elijah Harrison on 12/19/23.
//

#include "laser.hpp"

// Ship forward declaration in laser.hpp completed in ship.hpp
#include "ship.hpp"

/************************************************************
 * Ship Laser constructor
 * public constructor used by Ship::fireLaser()
 ************************************************************/
Laser::Laser(const Interface & ui, const Ship * ptr) : Laser(ui) {
   // get non-const copy of ship (we don't want to modify the ship)
   Ship ship = *ptr;
   
   // use Ship object to launch laser (this)
   p = ship.getPosition();
   v = ship.getVelocity();
   
   // offset laser to front of ship
   p += Position::forward(ship.getRotation()) * ship.getRadius();
   
   // fire!!
   v += launchVelocity(ship.getRotation());
}

/************************************************************
 * # Laser::launchVelocity
 * helper that creates a new Velocity vector
 * with `magnitude = LASER_SPEED` macro
 * at `angle = firingAngle` (should be current ship angle)
 ************************************************************/
Velocity Laser::launchVelocity(double firingAngle) {
   return Velocity::forward(firingAngle) * LASER_SPEED;
}

/************************************************************
 * Laser operator =
 * not sure why this was needed.
 * Removing this causes build to fail?
 ************************************************************/
Laser & Laser::operator = (const Laser & rhs) {
   p = rhs.p;
   v = rhs.v;
   setDeathTimer(rhs.timer); // sets timerOn to true
   return *this;
}
