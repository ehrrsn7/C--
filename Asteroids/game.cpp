//
//  game.cpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/7/20.
//

#include "game.hpp"

#include "physics components/physicsFormulas.hpp"

#include <limits> // for getClosestDistance()
#include <algorithm>

// initialization
void Game::setUpScreen(Position tl, Position br) {
   center.set(0, 0); // center of screen
   screenLeft   = tl.getX();
   screenRight  = br.getX();
   screenBottom = br.getY();
   screenTop    = tl.getY();
   score.set(Position(screenLeft + 10, screenTop - 15));
   level.set(Position(screenRight - 55, screenTop - 15));

   std::cout << "Screen left:  " << screenLeft << std::endl;
   std::cout << "Screen right: " << screenRight << std::endl;
   std::cout << "Screen up:    " << screenTop << std::endl;
   std::cout << "Screen down:  " << screenBottom << std::endl;
}

void Game::fireLaser() {
   // handle "machine gun firing here"
   // define firing rate above
   // (at desired rate:)
   // get new laser from ship->fire()
   // push new laser onto lasers (vector<>)
   if (ship->getLaserFiringDelayTimer() <= 0) {
      lasers.push_back(ship->fire());
      ship->setLaserFiringDelayTimer();
   }
}

double dist(Position & p1, Position & p2) {
   return sqrt((p1.getX() * p1.getX()) + (p2.getX() * p2.getX()));
}

Rock* Game::buildRock(int whichRock, Position pInit, Velocity vInit, bool isInitial) {

   /* initialize p and v */

   // condition: don't randomize if pInit is non-default
   if (pInit.getMagnitude() < 10) {

      // default v randomized in individual rock constructors
      // default p [aka Position(0,0)] set to random location:
      double newX = random(screenLeft, screenRight);
      double newY = random(screenBottom, screenTop);
      pInit.set(newX, newY);

      /* handle ship—rock buffer */

      // condition: only on initialization
      if (isInitial) {

         // error condition: ship has not been created (should not happen)
         if (ship != NULL) { // if ship is null (error), then skip

            Position shipPoint = ship->getPosition();
               double buffer = 100;

               // while dist(rock, ship) < buffer, then REDO RANDOM POINT
               while (dist(shipPoint, pInit) < buffer) { // redo random point
                  std::cout << ">>> newRock.p within buffer @ ("
                     << newX << ", "
                     << newY << ")"
                     << ", recalculate." << std::endl;
                  newX = random(screenLeft, screenRight);
                  newY = random(screenBottom, screenTop);
                  pInit.set(newX, newY);

               } // end while rock within buffer radius
         } // end if ship != NULL
      } // end if isInitial
   } // end if pInit != default P(0,0)

   // create new rock
   Rock* newRock = NULL;
   switch(whichRock) {
      case bigRock:
         newRock = new BigRock(pInit, vInit);
         break;
      case mediumRock:
         newRock = new MediumRock(pInit, vInit);
         break;
      case smallRock:
         newRock = new SmallRock(pInit, vInit);
         break;
   }
   return newRock;
}

void Game::asteroidBelt() {
   for (int i = 0; i < Rock::amountInit; i++) {
      std::cout << i << ") asteroid belt \n";
      Position pInit;
      Velocity vInit;
      rocks.push_back(buildRock(bigRock, pInit, vInit, true));
   }
}

void Game::update(MovingObject & obj) { obj.update(); }

void Game::update(MovingObject * obj) {
   if (obj == NULL) return;
   update(*obj);
}

void Game::wrap() {
   // wrap ship
   if (ship != NULL)
      wrap(ship);

   // wrap lasers
   // for (std::vector<Laser>::iterator it = lasers.begin(); it < lasers.end(); ++it, ++i) {
   for (Laser & laser : lasers) wrap(&laser);

   // wrap rocks
   for (Rock * rock : rocks) wrap(rock);
}

void Game::wrap(MovingObject * obj) {
   if (obj == NULL) return;

   bool debug = false;
   if (debug) printf("wrap() called ");
   double buffer = obj->getRadius() + 10;

   /* SCREEN SIDE VALS REFERENCE
   * screen left   == topLeft.getX() - obj->getRadius()
   * screen right  == bottomRight.getX() + obj->getRadius()
   * screen bottom == bottomRight.getY() - obj->getRadius()
   * screen top    == topLeft.getY() + obj->getRadius()
   */

   // obj x < screen left => screen right
   if (obj->getPosition().getX() < screenLeft - buffer) {
      obj->setPosition(screenRight + buffer, obj->getPosition().getY());
      if (debug) printf("//  Wrap left -> right");
   }

   // obj x > screen right => screen left
   else if (obj->getPosition().getX() > screenRight + buffer) {
      obj->setPosition(screenLeft - buffer, obj->getPosition().getY());
      if (debug) printf("//  Wrap right -> left");
   }

   // obj y < screen bottom => screen top
   if (obj->getPosition().getY() < screenBottom - buffer) {
      obj->setPosition(obj->getPosition().getX(), screenTop + buffer);
      if (debug) printf("//  Wrap bottom -> top");
   }

   // obj y > screen top => screen bottom
   else if (obj->getPosition().getY() > screenTop + buffer) {
      obj->setPosition(obj->getPosition().getX(), screenBottom - buffer);
      if (debug) printf("//  Wrap top -> bottom");
   }

   if (debug) printf("\n");
}

void Game::wrap(std::vector<MovingObject> & objects) {
   for (MovingObject & obj : objects) wrap(&obj);
}

void Game::wrap(std::vector<MovingObject *> & objects) {
   for (MovingObject * obj : objects) wrap(obj);
}

void Game::handleCollisions() {
   // skip this method if ship is no longer alive
   if (ship == NULL || !ship->isAlive()) return;

   // handle collisions
   for (Rock * rock : rocks) {
      handleCollision(ship, rock);
      for (Laser & laser : lasers) handleCollision(&laser, rock);
   }
}

void Game::handleCollision(MovingObject * obj, Rock * rock) {
   if (rock == NULL || !checkCollision(obj, rock)) return;

   // collision
   splitRock(rock, *obj);
   if (rock != NULL) rock->hit();
   score.add(rock->getScoreAmount());
   obj->hit();
}

std::pair<Velocity, Velocity> generateOffsetVelocity(MovingObject rock, MovingObject obj) {
   // generate offset velocity between rocks
   // we don't want the split rocks to continue on same point

   // rules for new velocity:
   // - needs to be within 15° of normal to initial velocity
   // - offset speeds depend on size of rock (get info from rocks.hpp based on rockID)

   // get total mass/momentum information
   double totalMomentum = rock.getMomentum() + obj.getMomentum();
   double totalMass     = rock.getMass()     + obj.getMass();

   // get final speed/angleRadians from mass/momentum info
   double finalSpeed = totalMomentum / totalMass; // velocity = ρ / m
   double finalAngle = (
      obj.getVelocity().getAngleRadians() +
      rock.getVelocity().getAngleRadians()) / 2;

   // get angle deviance from finalAngle, randomly calculated between 0° and 15°
   double randomAngleOffset = rad(random(0, 15)); // = ø

   // set final velocities of new rocks based on final speed, angle and ø offset
   Velocity offsetVelocity1, offsetVelocity2;
   offsetVelocity1.setMagnitude(finalSpeed, finalAngle - randomAngleOffset);
   offsetVelocity2.setMagnitude(finalSpeed, finalAngle + randomAngleOffset);

   // package and return
   return std::pair<Velocity, Velocity>(offsetVelocity1, offsetVelocity2);
}

void Game::splitRock(Rock * rock, MovingObject & obj) {
   std::cout << "splitRock(*" << rock->getName() << ");\n"; // debug

   // create index to identify which rocks which will be split into
   int newRockIndex = rock->getNextRockIndex();

   /* do what the good book says */
   // Create 2 pointers for new rocks, set them to null
   Rock* newRock1 = NULL;
   Rock* newRock2 = NULL;

   // generate offset velocity between rocks
   auto offsetVelocityPair = generateOffsetVelocity(*rock, obj);
   Velocity offsetV1 = offsetVelocityPair.first; // unpack
   Velocity offsetV2 = offsetVelocityPair.second;

   // Create the new Rock ptrs
   newRock1 = buildRock(newRockIndex, rock->getPosition(), rock->getVelocity() + offsetV1, false);
   newRock2 = buildRock(newRockIndex, rock->getPosition(), rock->getVelocity() + offsetV2, false);

   // add them to vector<Rock*>
   rocks.push_back(newRock1);
   rocks.push_back(newRock2);
}

bool Game::checkCollision(MovingObject & obj1, MovingObject & obj2) {
   return getClosestDistance(obj1, obj2) < obj1.getRadius() + obj2.getRadius();
}

bool Game::checkCollision(MovingObject * obj1, MovingObject * obj2) {
if (obj1 == NULL || obj2 == NULL) return false;
return checkCollision(*obj1, *obj2);
}

double Game::getClosestDistance(MovingObject & obj1, MovingObject & obj2) {
// find the maximum distance traveled
double dMax = std::max(abs(obj1.getVelocity().getX()), abs(obj1.getVelocity().getY()));
dMax = std::max(dMax, abs(obj2.getVelocity().getX())); // Between previous max and |obj2.dx|
dMax = std::max(dMax, abs(obj2.getVelocity().getY())); // Between previous max and |obj2.dy|
dMax = std::max(dMax, 0.1); // when dx and dy are 0.0. Go through the loop once.

double distMin = std::numeric_limits<float>::max();
for (double i = 0.0; i <= dMax; i++) {
   Position point1(
      obj1.getPosition().getX() + (obj1.getVelocity().getX() * i / dMax),
      obj1.getPosition().getY() + (obj1.getVelocity().getY() * i / dMax));
   Position point2(
      obj2.getPosition().getX() + (obj2.getVelocity().getX() * i / dMax),
      obj2.getPosition().getY() + (obj2.getVelocity().getY() * i / dMax));

   double xDiff = point1.getX() - point2.getX();
   double yDiff = point1.getY() - point2.getY();

   double distSquared = (xDiff * xDiff) +(yDiff * yDiff);

   distMin = std::min(distMin, distSquared);
}

return sqrt(distMin);
}

void Game::cleanUpZombies() {
   cleanUpShip();
   cleanUpRocks();
   cleanUpLasers();
}

void Game::cleanUpShip() {
   if (ship != NULL)
      if (!ship->isAlive())
         ship = NULL;
}

void Game::cleanUpLasers() {
   std::vector<Laser>::iterator it = lasers.begin();
   while (it != lasers.end()) {
      if (!(*it).isAlive()) {
         it = lasers.erase(it);
         return;
      }
      else ++it;
   }
}

void Game::cleanUpRocks() {
   std::vector<Rock*>::iterator it = rocks.begin();
   while (it != rocks.end()) {
      if ((*it) == NULL) break; // just in case
      if (!(*it)->isAlive()) {
         std::cout << "removing " << (*it)->getName() << std::endl;
         it = rocks.erase(it);
         return;
      }
      else ++it;
   }
}

void Game::reset() {
   resetShip();
   removeAllLasers();
   resetAllRocks();
   resetScore();
}

void Game::resetShip() {
   Ship * newShip = NULL;
   newShip = new Ship();
   ship = newShip;
}

void Game::resetAllRocks() {
   removeAllRocks();
   asteroidBelt();
}

void Game::removeAllRocks() {
   std::vector<Rock*>::iterator it = rocks.begin();
   while (it != rocks.end()) it = rocks.erase(it);
}

void Game::removeAllLasers() {
   std::vector<Laser>::iterator it = lasers.begin();
   while (it != lasers.end()) it = lasers.erase(it);
}

void Game::resetScore() {
   score.reset();
}
