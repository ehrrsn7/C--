//
//  game.hpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/7/20.
//

#pragma once

// import
#include <iostream> // debugging
#include <stdio.h>
#include <vector> // dynamic arrays
#include <map> // held keys
#include <cmath>

#include "vector/point.hpp" // point
#include "ui/uiInteract.hpp" // user interaction

// import game objects
#include "game objects/moving objects/movingObject.hpp"
#include "game objects/moving objects/ship.hpp"
#include "game objects/moving objects/laser.hpp"
#include "game objects/moving objects/rocks.hpp"
#include "game objects/ui (objects)/score.hpp"
#include "game objects/ui (objects)/level.hpp"

class Game {
private:
   // screen positioning
   float screenLeft;
   float screenRight;
   float screenBottom;
   float screenTop;
   Point center;

   // game objects
   Ship* ship;
   std::vector<Laser> lasers;
   std::vector<Rock*> rocks;
   Level level;
   Score score;

   // in game.cpp:
   void setUpScreen(Point tl, Point br);
   void fireLaser();
   void asteroidBelt();
   Rock * buildRock(int whichRock, Point pInit, Velocity vInit, bool isInitial);
   void update(MovingObject & obj);
   void update(MovingObject * obj);
   void wrap();
   void wrap(MovingObject* obj);
   void wrap(std::vector<MovingObject> & collection);
   void wrap(std::vector<MovingObject *> & collection);

   void handleCollisions();
   void handleCollision(MovingObject * obj, Rock * rock);
   bool checkCollision(MovingObject & obj1, MovingObject & obj2);
   bool checkCollision(MovingObject * obj1, MovingObject * obj2);
   float getClosestDistance(const MovingObject & obj1, const MovingObject & obj2);

   // "bring out ur deaaaaaaaaaad"
   void cleanUpZombies();
   void cleanUpShip();
   void cleanUpLasers();
   void cleanUpRocks();

   // build two new rocks from one existing rock
   void splitRock(Rock * rock, MovingObject & obj);

   // helps us reset everything
   void reset();
   void resetShip();
   void resetAllRocks();
   void removeAllRocks();
   void removeAllLasers();
   void resetScore();

public:
   Game(Point topLeft, Point bottomRight) {
      /* Set up the initial conditions of the game */
      setUpScreen(topLeft, bottomRight);

      /* GAME OBJECTS */
      ship = new Ship();
      asteroidBelt();
   }

   ~Game() {}

   void update() {
      update(ship);
      for (Laser laser : lasers) update(laser);
      for (Rock * rock : rocks) update(rock);

      wrap();
      handleCollisions();
      cleanUpZombies();

      // TODO: handle game states
      // for example: when 0 rocks are on the screen, initiate next—level sequence
   }

   // 'const Interface & ui'
   void display(const Interface & ui) {
      if (ship != NULL) ship->display();

      // display lasers)
      for (Laser it : lasers) it.display();

      // display rocks
      for (Rock* it : rocks)
         if (it != NULL)
            it->display();

      level.display();
      score.display();
   }

   void handleInput(const Interface & ui) {
      /* heldKeys defined/handled in uiInteract.cpp/.hpp */

      // reset
      if (ui.getHeldKey(keys::R)) reset();

      // quit
      if (ui.getHeldKey(keys::ESC)) exit(0);

      /* ship controls */
      // handle NULL ship
      if (ship != NULL) {

         // up
         // accelerate ship
         if (ui.getHeldKey(keys::UP)) ship->accelerate();

         // down
         // apply ship 'brakes'
         if (ui.getHeldKey(keys::DOWN)) ship->applyBrakes();

         // space
         // fire laser
         if (ui.getHeldKey(keys::SPACE)) fireLaser();

         // left / right
         // rotate (accordingly)
         if (ui.getHeldKey(keys::LEFT) || ui.getHeldKey(keys::RIGHT)) {
            if (ui.getHeldKey(keys::LEFT))  ship->rotate((int)keys::LEFT);
            if (ui.getHeldKey(keys::RIGHT)) ship->rotate((int)keys::RIGHT);
         }
         else 
            ship->stopRotating();
      }
   }
};
