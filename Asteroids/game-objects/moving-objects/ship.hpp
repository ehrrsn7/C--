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

#define SHIP_ROTATE_AMOUNT 5.0 // in rad/s
#define SHIP_INITIAL_ANGLE 90.0
#define SHIP_ACCELERATE_AMOUNT 700.0 // pixels per second per second
#define SHIP_SPEED_LIMIT 1000.0 // pixels per second
#define SHIP_BRAKES_AMOUNT 1.0
#define SHIP_FRICTION_AMOUNT 1.0
#define SHIP_RADIUS 2.0 // px
#define SHIP_MASS 200.0 // kg
#define SHIP_MAX_SPEED 500.0 // px/s

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
         applyBrakes();
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
      auto dv_percent_brakes = 1 - (30 * sigmoid(SHIP_BRAKES_AMOUNT) * abs(ui.frameRate()));
      v *= dv_percent_brakes;
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
   }

   void update() override {
      if (!isAlive() || isNull()) return; // quick exit
      if (brake) applyBrakes();
      MovingObject::update();
      updateLaserFiringDelayTimer();
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
         break;
      }
   }

   // getters
   Laser fire() {
      auto ang = rotation; // - rad(SHIP_INITIAL_ANGLE);
      std::cout << "laser fire angle " << deg(ang) << "º\n";
      setLaserFiringDelayTimer();
      return Laser(ui, ang, p, v, r);
   }
   
   double getLaserFiringDelayTimer() const { return laserFiringDelayTimer; }

   // setters
   void enableBrakes(bool brake = true) { this->brake = brake; }
   void setLaserFiringDelayTimer(double delay = FIRE_DELAY_TIME) { laserFiringDelayTimer = delay; } /* from laser.hpp */
   void stopRotating() { setRotation(0.0); }

   void updateLaserFiringDelayTimer() {
      if (laserFiringDelayTimer < 0.0) return;
      laserFiringDelayTimer -= 1.0 * abs(ui.frameRate());
   }
};
