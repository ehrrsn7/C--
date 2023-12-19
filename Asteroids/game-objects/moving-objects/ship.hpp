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
#define SHIP_ACCELERATE_AMOUNT 2000.0 // pixels per second per second
#define SHIP_SPEED_LIMIT 500 // pixels per second
#define SHIP_BRAKES_AMOUNT 10
#define SHIP_FRICTION_AMOUNT 1
#define SHIP_RADIUS 2 // px
#define SHIP_MASS 200 // kg
#define SHIP_MAX_SPEED 500 // px/s

class Ship : public MovingObject {

protected:
   Velocity brakesAmount;
   Velocity frictionAmount;
   double laserFiringDelayTimer;
   bool brake;

public:
   Ship(const Interface & ui, bool brake = false, bool friction = false) : MovingObject(ui) {
      setName("Player Ship");
      setGameObjectID(playerShip);
      setThrust(SHIP_ACCELERATE_AMOUNT);
      setRadius(SHIP_RADIUS);
      setRotation(rad(SHIP_INITIAL_ANGLE));
      setFriction(friction);
      brakesAmount = Velocity();
      frictionAmount = Velocity();
      laserFiringDelayTimer = 0.0;
      this->brake = brake;
   }

   void display() override {
      drawShip(
         getPosition(), 
         deg(getRotation()) - SHIP_INITIAL_ANGLE, 
         getRadius()
      );
   }

   void update(const Interface & ui) override {
      if (!isAlive() || isNull()) return; // quick exit

      MovingObject::update(ui);

      auto dv_percent_brakes = !brake || abs(v.getMagnitude()) <= 0.01 ? 1 : 1 - (30 * sigmoid(SHIP_BRAKES_AMOUNT) * abs(ui.frameRate()));
      auto dv_percent_friction = !brake || abs(v.getMagnitude()) <= 0.01 ? 1 : 1 - (30 * sigmoid(SHIP_FRICTION_AMOUNT) * abs(ui.frameRate()));
      std::cout << "ship speed " << (v.getMagnitude() > .01 ? v.getMagnitude() : 0) << " "
          << "brakes amount " << dv_percent_brakes * 100 << "% "
          << "friction amount " << dv_percent_friction * 100 << "% "
          << std::endl;

      // apply brakes
      v *= dv_percent_brakes;
      if (brake) brake = false; // unset after pressing the brake button

      // apply friction
      v *= dv_percent_friction;

      // decrement laser firing delay timer
      updateLaserFiringDelayTimer();

      // limit speed
      if (v.getMagnitude() > SHIP_MAX_SPEED) {
         std::cout << "Max speed (" << SHIP_MAX_SPEED << ") reached.\n";
         applyBrakes();
      }
   }

   void rotate(keys direction) {
      if (!isAlive() || isNull()) return; // quick exit
      switch (direction) {
      case keys::LEFT:
         rotation = SHIP_ROTATE_AMOUNT;
         break;
      case keys::RIGHT:
         rotation = -SHIP_ROTATE_AMOUNT;
         break;
      default:
         rotation = 0.0;
         break;
      }
   }

   // getters
   Laser fire() { return Laser(ui, rotation, p, v, r); }
   double getLaserFiringDelayTimer() const { return laserFiringDelayTimer; }

   // setters
   void applyBrakes() { brake = true; }
   void setLaserFiringDelayTimer() { laserFiringDelayTimer = FIRE_DELAY_TIME; } /* from laser.hpp */
   void stopRotating() { setRotation(0.0); }

   void updateLaserFiringDelayTimer() {
      if (laserFiringDelayTimer < 0.0) return;
      laserFiringDelayTimer -= 1.0 * abs(ui.frameRate());
   }
};
