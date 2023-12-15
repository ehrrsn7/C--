//
//  ship.hpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/7/20.
//

#pragma once

#include <stdio.h>
#include <string>

#include "movingObject.hpp"
#include "laser.hpp"

#ifdef __APPLE__
#include "uiInteract.hpp"
#endif
#ifdef _WIN32
#include "ui/uiInteract.hpp"
#endif

#ifdef __APPLE__
#include "physicsFormulas.hpp"
#endif
#ifdef _WIN32
#include "physics-components/physicsFormulas.hpp"
#endif

#define SHIP_ROTATE_AMOUNT 15 // in rad/s
#define SHIP_INITIAL_ANGLE 90
#define SHIP_ACCELERATE_AMOUNT 2.0
#define SHIP_SPEED_LIMIT 15 // pixels per second
#define SHIP_BRAKES_AMOUNT 1
#define SHIP_FRICTION_AMOUNT .1
#define SHIP_RADIUS 2 // px
#define SHIP_MASS 200 // kg
#define SHIP_MAX_SPEED 50 // px/s

class Ship : public MovingObject {

protected:
   Velocity brakesAmount;
   Velocity frictionAmount;
   double laserFiringDelayTimer;
   bool brake;

public:
   Ship(bool brake = false, bool friction = false) : brake(brake) {
      setName("Player Ship");
      setGameObjectID(rock);
      setThrust(SHIP_ACCELERATE_AMOUNT);
      setRadius(SHIP_RADIUS);
      setRotation(rad(SHIP_INITIAL_ANGLE));
      setFriction(friction);
      brakesAmount = Velocity();
      frictionAmount = Velocity();
      laserFiringDelayTimer = 0.0;
   }

   void display() override {
      drawShip(
         getPosition(), 
         deg(getRotation()) - SHIP_INITIAL_ANGLE, 
         getRadius()
      );
   }

   void update() {
      if (!isAlive()) return; // quick exit

      MovingObject::update();

      // apply brakes/friction
      if (brake) {
         // TODO: put a constraint here for min/max allowed velocity for calc
         getVelocity().add(getVelocity() * -(SHIP_BRAKES_AMOUNT / 10));
         brake = false; // unset after pressing the brake button
      }

      if (getFriction()) {
         getVelocity().add(getVelocity() * -(SHIP_FRICTION_AMOUNT / 10));
      }

      // decrement laser firing delay timer
      updateLaserFiringDelayTimer();

      // limit speed
      if (getVelocity().getMagnitude() > SHIP_MAX_SPEED) {
         std::cout << "Max speed (" << SHIP_MAX_SPEED << ") reached.\n";
         applyBrakes();
      }
   }

   void rotate(keys direction) {
      if (!isAlive()) return; // quick exit
      if (direction == keys::LEFT) setRotation(SHIP_ROTATE_AMOUNT);
      if (direction == keys::RIGHT) setRotation(-SHIP_ROTATE_AMOUNT);
   }

   void stopRotating() {
      // std::cout << "stop turning" << std::endl;
      setRotation(0.0);
   }

   void applyBrakes() { brake = true; }

   Laser fire() { return Laser(getRotation(), getPosition(), getVelocity(), getRadius()); }

   double getLaserFiringDelayTimer() const {
      return laserFiringDelayTimer;
   }
   void setLaserFiringDelayTimer() {
      laserFiringDelayTimer = FIRE_DELAY_TIME; // from laser.hpp
   }
   void updateLaserFiringDelayTimer() {
      if (laserFiringDelayTimer >= 0.0) {
         laserFiringDelayTimer -= 1.0/FPS;
         // std::cout << "laserFiringDelayTimer: " << laserFiringDelayTimer << std::endl; // debug
      }
   }
};
