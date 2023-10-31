/**********************************************************************
 * Source File: Vector
 **********************************************************************/

#include "vector.hpp"

#include "physicsFormulas.hpp"

void Vector::set(double x, double y) {
   setX(x);
   setY(y);
}

void Vector::add(double dx, double dy) {
   addX(dx);
   addY(dy);
}

void Vector::add(const Vector & v) {
   // v stands for ds/dt where s is the base vector
   add(v.getX(), v.getY());
}

void Vector::multiply(double magnitude) {
   multiplyX(magnitude * sin(getAngleRadians()));
   multiplyY(magnitude * cos(getAngleRadians()));
}

void Vector::setPolar(double magnitude, double angleRadians) {
   Vector::set(trigX(magnitude, angleRadians), trigY(magnitude, angleRadians));
}

void Vector::setMagnitude(double magnitude, double angleRadians) {
   setPolar(magnitude, angleRadians);
}

void Vector::addMagnitude(double magnitude, double angleRadians) {
   add(magnitude * sin(angleRadians), magnitude * cos(angleRadians));
}

void Vector::addPolar(double magnitude, double angleRadians) {
   addMagnitude(magnitude, angleRadians);
}

/* static */ Vector Vector::forward(double angleRadians) {
   return Vector(cos(angleRadians), sin(angleRadians));
}

Vector Vector::operator + (const Vector& rhs) {
   Vector newS;
   newS.add(rhs.getX(), rhs.getY());
   return newS;
}

Vector& Vector::operator += (const Vector& rhs) {
   add(rhs.getX(), rhs.getY());
   return *this;
}

Vector Vector::operator * (const double rhs) {
   Vector newS = *this;
   newS.multiply(rhs);
   return newS;
}

Vector& Vector::operator *= (const double rhs) {
   multiply(rhs);
   return *this;
}
