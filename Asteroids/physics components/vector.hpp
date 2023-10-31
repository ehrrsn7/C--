/**********************************************************************
 * Header File: Vector
 **********************************************************************/

#pragma once

#include <iostream>
#include <cassert>
#include <cmath> // for sin/cos (for now until physicsFormulas.h is done)

/**************************************************
 * prototypes
 **************************************************/
class Vector;
class Position;
class Velocity;
class Acceleration;
class Force;
class Gravity;
class TestPosition;
double mag(const Vector& s);

/**************************************************
 * CLASS Vector
 *    Base class for all classes with a need for
 *    an x and y component.
 **************************************************/
class Vector {
public:
   /**************************************************
    * Constructors
    **************************************************/
   Vector() : Vector(0.0, 0.0) {            } // default constructor
   Vector(double x, double y)  { set(x, y); } // normal "
   Vector(const Vector& s)     { *this = s; } // copy "
   Vector & operator = (const Vector & rhs) { // assignment operator '='
      set(rhs.getX(), rhs.getY()); return *this;
   }

   /**************************************************
    * Getters
    **************************************************/
   double getX() const { return x; }
   double getY() const { return y; }

   /**************************************************
    * Setters
    **************************************************/
   void setX(double x) { this->x = x; }
   void setY(double y) { this->y = y; }

   void set(double x, double y);
   void set(const Vector & s) { set(s.getX(), s.getY()); }

   /**************************************************
    * Adders
    **************************************************/
   void addX(double dx) { setX(getX() + dx); }
   void addY(double dy) { setY(getY() + dy); }

   void add(double dx, double dy);
   void add(const Vector & v);

   /**************************************************
    * Other Getters/Setters
    **************************************************/
   double getMagnitude() const      { return mag(*this); }
   double getAngleRadians() const   { return atan2(getX(), getY()); }
   double angle() const             { return getAngleRadians(); }

   void setPolar(double magnitude, double angleRadians);
   void setMagnitude(double magnitude, double angleRadians); // just an alias for setPolar

   void addPolar(double magnitude, double angleRadians);
   void addMagnitude(double magnitude, double angleRadians); // "

   /**************************************************
    * Operators
    **************************************************/
   Vector operator+ (const Vector& rhs);
   Vector& operator+= (const Vector& rhs);

protected:
   double x; // horizontal position (meters)
   double y; // vertical position (meters)

   friend class TestVector;
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Vector& rhs);
std::istream & operator >> (std::istream & in,        Vector& rhs);

/**************************************************
 * CLASS Position
 * A single position on the field in Meters.
 * Position is responsible for keeping track of
 * both the meters representation of the
 * Simulator and the pixels drawn to the screen
 * via the ogstream object.
 **************************************************/
class Position : public Vector {
public:
   Position() : Position(0.0, 0.0) { }                      // non-default constructor
   Position(double metersX, double metersY) : Vector(metersX, metersY) { } // default
   Position(const Vector & pt) { *this = pt; }              // copy constructor
   Position & operator = (const Position & pt);             // assignment operator '='

   double getMetersX() const { return getX(); }
   double getMetersY() const { return getY(); }
   double getPixelsX() const { return getMetersX() / metersFromPixels; }
   double getPixelsY() const { return getMetersY() / metersFromPixels; }

   double metersToPixels(double meters) { return meters / Position::metersFromPixels; }
   double pixelsToMeters(double pixels) { return pixels * Position::metersFromPixels; }

   void set(double x, double y) { Vector::set(x, y); }
   void set(const Position& p) { Vector::set(p.getX(), p.getY()); }
   void setMetersX(double xMeters) { setX(xMeters); }
   void setMetersY(double yMeters) { setY(yMeters); }
   void setMeters(double xMeters, double yMeters);
   void setMetersPolar(double magnitudeMeters, double angleRadians);
   void setPixelsX(double xPixels) { setMetersX(xPixels * metersFromPixels); }
   void setPixelsY(double yPixels) { setMetersY(yPixels * metersFromPixels); }
   void setPixels(double xPixels, double yPixels);

   void add(const Position& p) { Vector::add(p.getX(), p.getY()); }
   void add(const Velocity& dv, double dt);
   void addPixelsX(double dxPixels) { setPixelsX(getPixelsX() + dxPixels);  }
   void addPixelsY(double dyPixels) { setPixelsY(getPixelsY() + dyPixels);  }
   void addPixels(double dxPixels, double dyPixels);
   void addMetersX(double dxMeters) { setMetersX(getMetersX() + dxMeters); }
   void addMetersY(double dyMeters) { setMetersY(getMetersY() + dyMeters); }
   void addMeters(double dxMeters, double dyMeters);

   double getZoom() const { return metersFromPixels; }
   void setZoom(double metersFromPixels);

   Position operator+ (const Position & rhs) const;
   Position& operator+= (const Position & rhs);

   Position operator- (const Position & rhs); // subtraction
   Position operator- (); // negative

private:
   static double metersFromPixels;
   friend class TestPosition;
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& rhs);
std::istream & operator >> (std::istream & in,        Position& rhs);

// simple struct to provide equivalent of class structure without the overhead
struct PT {
   int x;
   int y;
};

/**************************************************
 * CLASS Velocity
 * A change in Position.
 **************************************************/
class Velocity : public Vector {

// to not over-complicate things, let's rely on Vector's get/set components
// for our getters/setters in the child classes:

// getX()       | substitutes get dx
// getY()       | substitutes get dy
// magnitude()  | substitutes get speed

public:
   // constructors
   Velocity() : Vector(0.0, 0.0)  {                      }  // default constructor
   Velocity(double dx, double dy) { Vector::set(dx, dy); }  // normal "
   Velocity(const Velocity& s)    { *this = s;           }  // copy "
   Velocity & operator = (const Velocity & rhs);            // assignment operator '='

   // set
   void set(double x, double y) { Vector::set(x, y); }
   void set(const Velocity& v) { Vector::set(v.getX(), v.getY()); }

   // add
   void add(const Velocity& dv) {
      Vector::add(dv.getX(), dv.getY()); // call parent add
   }

   // operators
   Velocity operator+ (const Velocity& rhs) const { // rhs : Δt
      return Velocity(x + rhs.x, y + rhs.y);
   }

   Velocity& operator+= (const Velocity& rhs) { // rhs : Δt
      add(rhs);
      return *this;
   }

   Position operator* (const double rhs) { // rhs = Δt
      // v{this} * Δt{rhs} -> Δp{Position}
      return toPosition(rhs);
   }

private:
   // helper methods
   Position toPosition(const double dt) {
      return Position(getX() * dt, getY() * dt);
   }

   friend class TestVelocity;
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Velocity& rhs);
std::istream & operator >> (std::istream & in,        Velocity& rhs);

/**************************************************
 * CLASS Acceleration
 * A change in Velocity.
 **************************************************/
class Acceleration : public Vector {

public:
   // constructors
   Acceleration() : Vector(0.0, 0.0)    {                        }   // default constructor
   Acceleration(double ddx, double ddy) { Vector::set(ddx, ddy); }   // normal "
   Acceleration(const Acceleration& s)  { *this = s;             }   // copy "
   Acceleration & operator = (const Acceleration & rhs) {            // assignment operator '='
      Vector::set(rhs.getX(), rhs.getY()); return *this;
   }

   // set
   void set(double x, double y) { Vector::set(x, y); }
   void set(const Acceleration& a) { Vector::set(a.getX(), a.getY()); }

   // add
   void add(const Acceleration& da) {
      Vector::add(da.getX(), da.getY());
   }

   // operators
   Acceleration operator+ (const Acceleration& rhs) { // rhs : Δt
      Acceleration newA = *this;
      newA.add(rhs);
      return newA;
   }

   Acceleration& operator+= (const Acceleration& rhs) { // rhs : Δt
      add(rhs);
      return *this;
   }

   Velocity operator* (const double rhs) { // rhs = Δt
      // v{this} * Δt{rhs} -> Δp{Position}
      return toVelocity(rhs);
   }

private:
   // helper methods
   Velocity toVelocity(const double dt) {
      return Velocity(getX() * dt, getY() * dt);
   }

   friend class TestAcceleration;
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Acceleration& rhs);
std::istream & operator >> (std::istream & in,        Acceleration& rhs);

/**************************************************
 * CLASS Force
 * Acceleration integrated by mass.
 **************************************************/
class Force : public Vector {

public:
   // constructors
   Force() : Vector(0.0, 0.0)  {                      }  // default constructor
   Force(double fx, double fy) { Vector::set(fx, fy); }  // normal "
   Force(const Force& s)       { *this = s;           }  // copy "
   Force & operator = (const Force & rhs) {              // assignment operator '='
     Vector::set(rhs.getX(), rhs.getY()); return *this;
  }

   // set
   void set(double x, double y) { Vector::set(x, y); }
   void set(const Force& f) { Vector::set(f.getX(), f.getY()); }

   // add
   void add(const Force dF) {
      Vector::add(dF.getX(), dF.getY());
   }

   // operators
   Force operator+ (const Force& rhs) { // rhs : ΔF
      Force newF = *this;
      newF.add(rhs);
      return newF;
   }

   Force& operator+= (const Force& rhs) { // rhs : ΔF
      add(rhs);
      return *this;
   }

   Acceleration operator/ (const double rhs) { // rhs : mass
      return toAcceleration(rhs);
   }

private:
   // helper methods
   Acceleration toAcceleration(double mass) const {
      return Acceleration(getX() / mass, getY() / mass);
   }

   friend class TestForce;
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Force& rhs);
std::istream & operator >> (std::istream & in,        Force& rhs);

/**************************************************
 * CLASS Gravity
 * A special kind of force which describes
 * force due to gravity.
 **************************************************/
class Gravity : public Force {

public:
   // constructors
   Gravity() : Force(0.0, 0.0)   {                      }   // default constructor
   Gravity(double fx, double fy) { Vector::set(fx, fy); }   // normal "
   Gravity(const Gravity& s)     { *this = s;           }   // copy "
   Gravity & operator = (const Gravity & rhs) {             // assignment operator '='
      Vector::set(rhs.getX(), rhs.getY()); return *this;
   }

   // set
   void set(double x, double y) { Vector::set(x, y); }
   void set(const Gravity& g) { Vector::set(g.getX(), g.getY()); }

   // add
   void add(const Gravity dF) {
      Vector::add(dF.getX(), dF.getY());
   }

   // operators
   Gravity operator+ (const Gravity& rhs) { // rhs : ΔG
      Gravity newG = *this;
      newG.add(rhs);
      return newG;
   }

   Gravity& operator+= (const Gravity& rhs) { // rhs : ΔG
      add(rhs);
      return *this;
   }

   Acceleration operator/ (const double rhs) { // rhs : mass
      return toAcceleration(rhs);
   }

private:
   // helper methods
   Acceleration toAcceleration(double mass) const {
      return Acceleration(getX() / mass, getY() / mass);
   }

   friend class TestGravity;
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Gravity& rhs);
std::istream & operator >> (std::istream & in,        Gravity& rhs);
