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
#include "physicsFormulas.hpp"
#include "uiInteract.hpp"
#endif
#ifdef _WIN32
#include "physics-components/physicsFormulas.hpp"
#include "ui/uiInteract"
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

   void limitSpeed() {
      if (abs(v.getMagnitude()) <= 0.01) return;
      
      // limit speed
      if (v.getMagnitude() > SHIP_MAX_SPEED) {
         std::cout << "Max speed (" << SHIP_MAX_SPEED << ") reached.\n";
         enableBrakes();
      }
   }
   
   void applyFriction() {
      if (abs(v.getMagnitude()) <= 0.01) return;
      
      // apply friction
      if (friction) {
         auto dv_percent_friction = 1 - (30 * sigmoid(SHIP_FRICTION_AMOUNT) * abs(ui.frameRate()));
         v *= dv_percent_friction;
      }
   }
   
   void applyBrakes() {
      if (abs(v.getMagnitude()) <= 0.01) return;
      
      // apply brakes
      if (brake) {
         auto dv_percent_brakes = 1 - (30 * sigmoid(SHIP_BRAKES_AMOUNT) * abs(ui.frameRate()));
         v *= dv_percent_brakes;
         brake = false; // unset after pressing the brake button
      }
   }
   
public:
   Ship(const Interface & ui, bool brake = false, bool friction = false) : MovingObject(ui) {
      name = "Player Ship";
      gameObjectID = playerShip;
      thrust = SHIP_ACCELERATE_AMOUNT;
      r = SHIP_RADIUS;
      rotation = rad(SHIP_INITIAL_ANGLE);
      this->friction = friction;
      brakesAmount = Velocity();
      frictionAmount = Velocity();
      laserFiringDelayTimer = 0.0; // ! - maybe make this nullable?
      this->brake = brake;
   }

   void display() override {
      double a = deg(rotation) - SHIP_INITIAL_ANGLE;
      drawShip(p, a, r);
      std::cout << p << std::endl;
   }

   void update() override {
      if (!isAlive() || isNull()) return; // quick exit
      updateLaserFiringDelayTimer();
      applyBrakes();
      applyFriction();
      limitSpeed();
   }

   void rotate(keys direction) {
      if (!isAlive() || isNull()) return; // quick exit
      switch (direction) {
      case keys::LEFT:
         rotation += SHIP_ROTATE_AMOUNT * ui.frameRate();
         break;
      case keys::RIGHT:
         rotation -= SHIP_ROTATE_AMOUNT * ui.frameRate();
         break;
      default:
         // rotation = 0.0;
         break;
      }
   }

   // getters
   Laser fire() { return Laser(ui, rotation, p, v, r); }
   double getLaserFiringDelayTimer() const { return laserFiringDelayTimer; }

   // setters
   void enableBrakes() { brake = true; }
   void setLaserFiringDelayTimer() { laserFiringDelayTimer = FIRE_DELAY_TIME; } /* from laser.hpp */
   void stopRotating() { setRotation(0.0); }

   void updateLaserFiringDelayTimer() {
      if (laserFiringDelayTimer < 0.0) return;
      laserFiringDelayTimer -= 1.0 * abs(ui.frameRate());
   }
};
