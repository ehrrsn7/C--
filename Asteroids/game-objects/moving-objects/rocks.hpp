//
//  rocks.hpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/14/20.
//

#pragma once

#include <iostream>

#include "movingObject.hpp"
#include "ui/uiDraw.hpp"

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
   Rock() {
      setName("Rock (unknown)");
      setGameObjectID(rock);
      rockIndex = unknownRock;
      setRadius(ROCK_RADIUS);
      setRotation(ROCK_ROTATE_SPEED * random(-1.0, 1.0));
      initializePosition();
      initializeVelocity();
      setScoreAmount(ROCK_SCORE);
   }

   Rock(Position pInit, Velocity vInit) : Rock() {
      initializePosition(pInit);
      initializeVelocity(vInit);
   }

   void display() override {
      // Draw asteroid at Position p and angle r
      drawLargeAsteroid(getPosition(), getRotation());
   }

   void initializeRotation();
   void initializePosition();
   void initializePosition(Position pInit);
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
   BigRock(Position pInit, Velocity vInit) : Rock(pInit, vInit) {
      setName("Big Rock");
      setGameObjectID(rock);
      rockIndex = bigRock;
      setRadius(BIG_ROCK_RADIUS);
      setRotation(BIG_ROCK_ROTATE_SPEED * random(-1.0, 1.0));
      setScoreAmount(BIG_ROCK_SCORE);
   }
};

class MediumRock : public Rock {
public:
   MediumRock(Position pInit, Velocity vInit) : Rock(pInit, vInit) {
      setName("Medium Rock");
      setGameObjectID(mediumRock);
      rockIndex = mediumRock;
      setRadius(MEDIUM_ROCK_RADIUS);
      setRotation(MEDIUM_ROCK_ROTATE_SPEED * random(-1.0, 1.0));
      setScoreAmount(MEDIUM_ROCK_SCORE);
   }

   MediumRock(Position pInit, Velocity vInit, Velocity vShipInit) :
      MediumRock(pInit, vInit)
   {
      setVelocity(getVelocity() + vShipInit);
   }

   void display() override {
      drawMediumAsteroid(getPosition(), getRotation());
   }
};

class SmallRock : public Rock {
public:
   SmallRock(Position pInit, Velocity vInit) : Rock(pInit, vInit) {
      setName("Small Rock");
      setGameObjectID(smallRock);
      rockIndex = bigRock;
      setRadius(SMALL_ROCK_RADIUS);
      setRotation(SMALL_ROCK_ROTATE_SPEED * random(-1.0, 1.0));
      setScoreAmount(SMALL_ROCK_SCORE);
   }

   SmallRock(Position pInit, Velocity vInit, Velocity vShipInit) :
      SmallRock(pInit, vInit)
   {
      setVelocity(getVelocity() + vShipInit);
   }

   void display() override {
      drawSmallAsteroid(getPosition(), getRotation());
   }
};