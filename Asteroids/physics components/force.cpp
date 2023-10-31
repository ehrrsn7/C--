/**********************************************************************
 * force.cpp
 * orbitSimulator
 **********************************************************************/

#include "vector.h"

/**************************************************
 * FORCE ostream insertion
 **************************************************/
std::ostream& operator << (std::ostream& out, const Force& rhs) {
   out << "(" << rhs.getX() << "N , " << rhs.getY() << "N)";
   return out;
}

/**************************************************
 * FORCE istream extraction
 **************************************************/
std::istream& operator >> (std::istream& in, Force& rhs) {
   double x, y;
   in >> x >> y;
   rhs.set(x, y);
   return in;
}
