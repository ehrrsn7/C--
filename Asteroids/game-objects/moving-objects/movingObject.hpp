//
//  movingObject.hpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/7/20.
//

#pragma once

#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

#include "physics-components/vector.hpp"
#define FPS 60.0

enum gameObjectEnumID {
   movingObject,
   rock,
   laser,
   playerShip,
   ufo,
   score,
   level
};

class MovingObject {
private:
   bool alive; // is alive y/n
   bool brake; // apply brakes/slow down object when brakes are activated
   bool friction; // apply friction/slow down object naturally
   bool timerOn; // self-destruct timer y/n
   double da; // angular velocity
   double dr; // orientation angle angular vel.
   double mass;
   double r; // radius
   double rotation; // orientation angle (in radians)
   double thrust;
   double timer;
   int gameObjectID;
   int i; // debug
   int scoreAmount;
   Position p;
   std::string name;
   Velocity v;

public:
   MovingObject() :
      alive        (true), // is alive y/n
      brake        (false), // apply brakes
      dr           (0.0), // orientation angle rot. vel. in deg. per second
      friction     (false), // apply friction/brakes
      gameObjectID (movingObject),
      mass         (1.0), // kg (default)
      name         ("* Moving object"),
      r            (10.0), // in pixels
      rotation     (0.0), // current orientation angle (degrees)
      scoreAmount  (0), // points to be added to score when destroyed (if applicable)
      thrust       (0.0), // acceleration in pixels/s/s
      timer        (0.0), // self-destruct timer in seconds
      timerOn      (false), // self-destruct timer y/n
      i            (0) // debug
      { }

   void update() {
      if (!alive) return;

      p.add(v);

      // update orientation angle ('rotation')
      rotation += dr / FPS;
      if (rotation < 0) rotation = M_PI * 2;
      else if (rotation > M_PI * 2) rotation = 0;

      // update timer (if timer == 0, do nothing)
      if (timerOn) {
         if (timer > 0) timer -= 1.0;
         else alive = false;
      }
   }

   void displayDebugUpdateInfo();
   void accelerate();
   void hit();

   // polymorphism
   virtual void display() { }

   // getters
   bool getFriction()    const { return friction; }
   bool isAlive()        const { return alive; }
   double getMass()      const { return mass; }
   double getMomentum()  const { return mass * v.getMagnitude(); }
   double getRadius()    const { return r; }
   double getRotation()  const { return rotation; }
   double getThrust()    const { return thrust; }
   int getGameObjectID() const { return gameObjectID; }
   int getScoreAmount()  const { return scoreAmount; }
   std::string getName() const { return name; }
   Position & getPosition() { return p; }
   Velocity & getVelocity() { return v; }

   // setters
   void setAlive(bool alive)              { this->alive = alive; }
   void setFriction(bool friction)        { this->friction = friction; }
   void setGameObjectID(int id)           { gameObjectID = id; }
   void setName(std::string name)         { this->name = name; }
   void setPosition(double x, double y)   { p = Position(x, y); }
   void setPosition(Position p)           { this->p = p; }
   void setPositionX(double x)            { p.setX(x); }
   void setPositionY(double y)            { p.setY(y); }
   void setRadius(double r)               { this->r = r; }
   void setRotation(double dr)            { this->dr = dr; }
   void setScoreAmount(int score)         { scoreAmount = score; }
   void setThrust(double thrust)          { this->thrust = thrust; }
   void setVelocity(Velocity v)           { this->v = v; }
   void setDeathTimer(double duration);
};
