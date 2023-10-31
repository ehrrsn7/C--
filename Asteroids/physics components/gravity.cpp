/**********************************************************************
 * gravity.cpp
 * orbitSimulator
 **********************************************************************/

#include "vector.h"

/**************************************************
 * GRAVITY ostream insertion
 **************************************************/
std::ostream& operator << (std::ostream& out, const Gravity& rhs) {
   out << "(" << rhs.getX() << "N , " << rhs.getY() << "N)";
   return out;
}

/**************************************************
 * GRAVITY istream extraction
 **************************************************/
std::istream& operator >> (std::istream& in, Gravity& rhs) {
   double x, y;
   in >> x >> y;
   rhs.set(x, y);
   return in;
}
