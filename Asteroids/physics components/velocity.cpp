/**********************************************************************
 * velocity.cpp
 * orbitSimulator
 **********************************************************************/

#include "vector.h"

Velocity& Velocity::operator= (const Velocity & rhs) {
   Vector::set(rhs.getX(), rhs.getY()); return *this;
}

/**************************************************
 * VELOCITY ostream insertion
 **************************************************/
std::ostream& operator << (std::ostream& out, const Velocity& rhs) {
   out << "(" << rhs.getX() << "m/s , " << rhs.getY() << "m/s)";
   return out;
}

/**************************************************
 * VELOCITY istream extraction
 **************************************************/
std::istream& operator >> (std::istream& in, Velocity& rhs) {
   double x, y;
   in >> x >> y;
   rhs.set(x, y);
   return in;
}
