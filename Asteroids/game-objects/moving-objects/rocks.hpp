//
//  rocks.hpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/14/20.
//

#pragma once

#include <iostream>

#include "movingObject.hpp"

#ifdef __APPLE__
#include "uiDraw.hpp"
#endif
#ifdef _WIN32
#include "ui/uiDraw.hpp"
#endif

#define ROCK_INIT_AMOUNT 3 // amount of rocks spawned in first level scene
#define ROCK_INIT_LAUNCH_FORCE 5 // force applied to rocks that are spawned in N

#define ROCK_RADIUS 10 // size of rock in px
#define BIG_ROCK_RADIUS 10
#define MEDIUM_ROCK_RADIUS 5
#define SMALL_ROCK_RADIUS 3

#define ROCK_ROTATE_SPEED 10 // rotational velocity of rocks in rad/s
#define BIG_ROCK_ROTATE_SPEED 10
#define MEDIUM_ROCK_ROTATE_SPEED 15
#define SMALL_ROCK_ROTATE_SPEED 20

#define ROCK_MASS 100 // mass of rocks in kg
#define BIG_ROCK_MASS 100
#define MEDIUM_ROCK_MASS 80
#define SMALL_ROCK_MASS 50

#define ROCK_SCORE 20
#define BIG_ROCK_SCORE 20
#define MEDIUM_ROCK_SCORE 50
#define SMALL_ROCK_SCORE 100

// rock ids
enum rockIndex {
   unknownRock,
   bigRock,
   mediumRock,
   smallRock,
   noRock
};

class Rock : public MovingObject {
protected:
   int rockIndex;

public:
   Rock(const Interface & ui) : MovingObject(ui) {
      setName("Rock (unknown)");
      setGameObjectID(rock);
      rockIndex = unknownRock;
      setRadius(ROCK_RADIUS);
      setRotation(ROCK_ROTATE_SPEED * random(-1.0, 1.0));
      initializePosition();
      initializeVelocity();
      setScoreAmount(ROCK_SCORE);
   }

   Rock(const Interface & ui, Position pInit, Velocity vInit) : Rock(ui) {
      initializePosition(pInit);
      initializeVelocity(vInit);
   }

   void display() override {
      // Draw asteroid at Position p and angle r
      drawLargeAsteroid(p, rotation);
   }

   void initializeRotation();
   void initializePosition();
   void initializePosition(Position pInit) { p = pInit; }
   void initializeVelocity();
   void initializeVelocity(Velocity vInit);

   const static int amountInit = ROCK_INIT_AMOUNT;

   // getters/setters
   int getRockIndex() { return rockIndex; }
   int getNextRockIndex() {
      switch(rockIndex) {
         case unknownRock:
         case bigRock:
         case mediumRock:
         case smallRock:
            return rockIndex + 1;
         default:
            return noRock;
      };
   }

   static int getRockRadius(int rockID) {
      switch (rockID) {
         case bigRock:    return BIG_ROCK_RADIUS;
         case mediumRock: return MEDIUM_ROCK_RADIUS;
         case smallRock:  return SMALL_ROCK_RADIUS;
         default:         return ROCK_RADIUS;
      }
   }

   static double getRockRotateSpeed(int rockID) {
      switch (rockID) {
         case bigRock:    return BIG_ROCK_ROTATE_SPEED;
         case mediumRock: return MEDIUM_ROCK_ROTATE_SPEED;
         case smallRock:  return SMALL_ROCK_ROTATE_SPEED;
         default:         return ROCK_ROTATE_SPEED;
      }
   }
};

class BigRock : public Rock {
public:
   BigRock(const Interface & ui, Position pInit, Velocity vInit) : Rock(ui, pInit, vInit) {
      name = "Big Rock";
      gameObjectID = bigRock;
      rockIndex = bigRock;
      r = BIG_ROCK_RADIUS;
      rotation = BIG_ROCK_ROTATE_SPEED * random(-1.0, 1.0);
      scoreAmount = BIG_ROCK_SCORE;
   }
};

class MediumRock : public Rock {
public:
   MediumRock(const Interface & ui, Position pInit, Velocity vInit) : Rock(ui, pInit, vInit) {
      name = "Medium Rock";
      gameObjectID = mediumRock;
      rockIndex = mediumRock;
      r = MEDIUM_ROCK_RADIUS;
      rotation = MEDIUM_ROCK_ROTATE_SPEED * random(-1.0, 1.0);
      scoreAmount = MEDIUM_ROCK_SCORE;
   }

   MediumRock(const Interface & ui, Position pInit, Velocity vInit, Velocity vShipInit) :
      MediumRock(ui, pInit, vInit)
   {
      setVelocity(v + vShipInit);
   }

   void display() override { drawMediumAsteroid(p, rotation); }
};

class SmallRock : public Rock {
public:
   SmallRock(const Interface & ui, Position pInit, Velocity vInit) : Rock(ui, pInit, vInit) {
      name = "Small Rock";
      gameObjectID = smallRock;
      rockIndex = smallRock;
      r = SMALL_ROCK_RADIUS;
      rotation = SMALL_ROCK_ROTATE_SPEED * random(-1.0, 1.0);
      scoreAmount = SMALL_ROCK_SCORE;
   }

   SmallRock(const Interface & ui, Position pInit, Velocity vInit, Velocity vShipInit) :
      SmallRock(ui, pInit, vInit)
   {
      setVelocity(v + vShipInit);
   }

   void display() override { drawSmallAsteroid(p, rotation); }
};
