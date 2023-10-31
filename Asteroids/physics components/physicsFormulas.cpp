/**********************************************************************
 * Source File: Physics Formulas
 *
 * (We have a collection of procedural functions here because each math
 * helper function does not retain state)
 **********************************************************************/

#include "physicsFormulas.h"  // header file
#include "movingObject.h"     // for MovingObject
#include "ship.h"             // for Projectile (for now)
#include "earth.h"            // for Earth

#include <cmath>              // for math functions

/**********************************************************************
 * Horizontal/Vertical Components
 *    Note: 'Vector&' is polymorphic -- it refers to either itself or
 *    any child of Vector.
 **********************************************************************/
double trigX(const double mag, const double angleRadians)
   { return mag * sin(angleRadians); }
double trigY(const double mag, const double angleRadians)
   { return mag * cos(angleRadians); }

double trigX(const Vector & v) { return trigX(mag(v), v.angle()); }
double trigY(const Vector & v) { return trigY(mag(v), v.angle()); }

double mag(const Vector& s) { return mag(s.getX(), s.getY()); }
double mag(double x, double y) { return sqrt(x*x + y*y); }

double deg(double angleRadians) { return 180 * angleRadians / M_PI; }
double rad(double angleDegrees) { return M_PI * angleDegrees / 180; }

/**********************************************************************
* Distance Functions
**********************************************************************/

/**************************************************
 * author: james helfrich
 **************************************************/
double computeDistance(const Position& pos1, const Position& pos2) {
  return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
              (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
}

/**************************************************
 * Has Collided
 * param: obj1 : Moving Object
 * param: obj2 : Moving Object
 * return: bool : the objects have collided
 * (aka distance between objects > too close
 * where 'too close' == object1.radius + object2.radius)
 **************************************************/
bool hasCollided(MovingObject & obj1, MovingObject & obj2) {
   return computeDistance(obj1.getPosition(), obj2.getPosition()) < (obj1.getRadius() + obj2.getRadius());
}

/**************************************************
 * distance(position1, position2)
 * Distance = √[(p1.x-p2.x)^2 + (p1.y-p2.y)^2]
 **************************************************/
double distance(const Position& p1, const Position& p2) {
   return computeDistance(p1, p2);
}

/**************************************************
 * Overloaded function for easy converting
 * distance(objects) -> distance(positions)
 * Distance = √[(p1.x-p2.x)^2 + (p1.y-p2.y)^2]
 **************************************************/
double distance(const MovingObject& obj1, const MovingObject& obj2) {
   return distance(obj1.getPosition(), obj2.getPosition());
}

/**********************************************************************
 * Time Functions
 **********************************************************************/

/**************************************************
 * time dilation
 * dilation = hours in Day * minutes in hour
 *    td - ratio of simulator time to real-world time
 *    hours in day - 24
 *    minutes in hour - 60
 **************************************************/
double timeDilation() {return 24 * 60; }

/**************************************************
* dilate time
* use timeDilation() to calculate adjusted deltaTime
**************************************************/
double dilateTime(double dt) { return timeDilation() * dt; }

/**************************************************
 * time per frame
 * frame time = dilation / frame rate
 *    tpf - real-world time in seconds for each frame in the simulator
 *    frame rate - fps defined in simulator, 30 in our case
 *    timeDilation - "
 **************************************************/
double timePerFrame() {return timeDilation() / FPS; }


/**********************************************************************
 * Pixels to meters/reverse conversions
 **********************************************************************/
/**************************************************
 * PIXELS TO METERS
 *
 * takes parameter pixels and converts it to meters
 * according to conversion constant (static double
 * defined in Position class)
 *
 * param - pixels : double
 * return - double
 **************************************************/
double pixelsToMeters(double pixels) {
  return Position().pixelsToMeters(pixels);
}

/**************************************************
 * METERS TO PIXELS
 *
 * takes parameter pixels and converts it to meters
 * according to conversion constant (static double
 * defined in Position class)
 *
 * param - meters : double
 * return - double
 **************************************************/
double metersToPixels(double meters) {
  return Position().metersToPixels(meters);
}

/**********************************************************************
 * Earth Functions
 **********************************************************************/

/**************************************************
 * earth rotation speed
 * speed = -(2π/frame rate) * (dilation / seconds in day)
 *    rf - rotation of the earth in radians per 1 frame
 *    frame rate - "
 *    timeDilation - "
 *    seconds in day - number of seconds for 1 earth rotation
 **************************************************/
double earthRotationSpeed() {
   return -2 * M_PI * timePerFrame() / SECONDS_IN_DAY;
}

/**************************************************
 * earth rotation speed
 * speed = -(2π/frame rate) * (dilation / seconds in day)
 *    rf - rotation of the earth in radians per 1 frame
 *    frame rate - "
 *    timeDilation - "
 *    seconds in day - number of seconds for 1 earth rotation
 * This function overloads the original, but we take
 * the actual change in time per frame as a parameter.
 * So, we'll just replace timePerFrame() with the
 * actual dt.
 * (MovingObject will handle the time dilation)
 **************************************************/
double earthRotationSpeed(double dt) {
   return -2 * M_PI * dt / SECONDS_IN_DAY;
}

/**********************************************************************
* Gravity Functions
**********************************************************************/

/**************************************************
 * height above the earth
 * h = √[x² + y²] - r
 *    √[x² + y²] -> distance from origin
 *    r - radius of earth
 **************************************************/
double calcHeight(const Position & p) {
   return sqrt(
      pow(p.getMetersX(), 2) +
      pow(p.getMetersY(), 2)
   ) - EARTH_RADIUS;
}

/**************************************************
 * height above the earth
 * h = √[(x2 - x1)² + (y2 - y1)²] - r
 *    √[x2² + y2²] -> distance from p1
 **************************************************/
double calcHeight(const Position & p, const Earth & e) {
   // should the earth not strictly be at the origin
   return sqrt(
      pow(p.getMetersX() - e.getPosition().getMetersX(), 2) +
      pow(p.getMetersY() - e.getPosition().getMetersY(), 2)
   ) - EARTH_RADIUS;
}

/**************************************************
 * direction of gravity pull
 * a = atan2(p.x2 - p.x2, p.y1 - p.y2)
 *    *note that x and y are backwards, this is on purpose...:L
 **************************************************/
double directionOfGravity(const Position& p1, const Position& p2) {
   return atan2(
      p1.getMetersX() - p2.getMetersX(),
      p1.getMetersY() - p2.getMetersY()
   );
}

/**************************************************
 * alias for directionOfGravity(Position, Position)
 * direction of gravity pull
 * a = atan2(p.x2 - p.x2, p.y1 - p.y2)
 **************************************************/
double directionOfGravity(const MovingObject & obj1, const MovingObject & obj2) {
   return directionOfGravity(obj1.getPosition(), obj2.getPosition());
}

/**************************************************
 * gravity due to mass equation
 * Fg = G * m1 m2 / d^2 @angle towards obj2
 * placed beneath directionOfGravity so that it sees it
 **************************************************/
Gravity forceDueToGravity(const MovingObject& obj1, const MovingObject& obj2) {
   Gravity g;
   g.setPolar(
      G * obj1.getMass() * obj2.getMass() / pow(distance(obj1, obj2), 2),
      directionOfGravity(obj1, obj2));
   return g;
}


/**************************************************
* gravity equation
* gh = g (r/(r + h))^2
**************************************************/
double calcGravity(double height) {
   return ACCEL_DUE_TO_GRAVITY_EARTH * (
      pow((EARTH_RADIUS / (EARTH_RADIUS + height)), 2)
   );
}

/**************************************************
* gravity equation
* gh = g (r/(r + h))^2
* but returns an Acceleration vector object in the
* direction of the origin
**************************************************/
Acceleration calcGravityVector(const Position& p) {
   Acceleration g;
   g.setPolar(
      calcGravity(calcHeight(p)),
      directionOfGravity(p, Position())
   );
   return g;
}

/**********************************************************************
 * Motion
 **********************************************************************/

/**************************************************
 * motion with constant acceleration
 * s = s0 + v0 * dt + 1/2 * a * dt^2
 **************************************************/
double aToD(const Acceleration& a, const Velocity& v0, double dt, double initialD) {
   return initialD + mag(v0) * dt + .5 * mag(a) * pow(dt, 2);
   // dEjA vUUUUoo 🥹🚗
}

/**************************************************
 * x component of motion with constant acceleration
 **************************************************/
double aToX(const Acceleration& a, const Velocity& v0, double dt, double initialD) {
   return initialD + v0.getX() * dt + .5 * a.getX() * pow(dt, 2);
   // return toX(aToD(a, v0, dt, initialD), Velocity(a * dt + v0).getAngleRadians());
}

/**************************************************
 * y component of motion with constant acceleration
 **************************************************/
double aToY(const Acceleration& a, const Velocity& v0, double dt, double initialD) {
   return initialD + v0.getY() * dt + .5 * a.getY() * pow(dt, 2);
   // return toX(aToD(a, v0, dt, initialD), Velocity(a * dt + v0).getAngleRadians());
}

/**************************************************
 * x component of velocity with constant acceleration
 **************************************************/
double aToDx(const Acceleration& a, const Velocity& v0, double dt) {
   return v0.getX() + a.getX() * dt;
}

/**************************************************
 * y component of velocity with constant acceleration
 **************************************************/
double aToDy(const Acceleration& a, const Velocity& v0, double dt) {
   return v0.getY() + a.getY() * dt;
   // return toY(aToV(a, v0, dt));
}

/**************************************************
* velocity with constant acceleration
**************************************************/
Velocity aToV(const Acceleration& a, const Velocity& v0, const double dt) {
   // return v0 + a * dt;
   return Velocity(aToDx(a, v0, dt), aToDy(a, v0, dt));
}
