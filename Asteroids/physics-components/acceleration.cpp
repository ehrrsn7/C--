/**********************************************************************
 * acceleration.cpp
 * orbitSimulator
 **********************************************************************/

#include "vector.hpp"

/* static */ Acceleration Acceleration::forward(double angleRadians) {
   return Acceleration(Vector::forward(angleRadians));
}

/**************************************************
 * ACCELERATION ostream insertion
 **************************************************/
std::ostream& operator << (std::ostream& out, const Acceleration& rhs) {
   out << "(" << rhs.getX() << "m/s/s , " << rhs.getY() << "m/s/s)";
   return out;
}

/**************************************************
 * ACCELERATION istream extraction
 **************************************************/
std::istream& operator >> (std::istream& in, Acceleration& rhs) {
   double x, y;
   in >> x >> y;
   rhs.set(x, y);
   return in;
}
