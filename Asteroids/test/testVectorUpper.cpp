/**********************************************************************
 * testVectorUpper.cpp
 * orbitSimulator
 **********************************************************************/

#include "testVector.h"

/********************
 * Constructors
 ********************/
void TestVector::UpperEdgeCase::test_default_constructor() const
{  // setup
   Vector v;
   // exercise
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

void TestVector::UpperEdgeCase::test_nondefault_Constructor () const
{  // setup
   Vector v(numeric_limits<double>::max(), numeric_limits<double>::max());
   // exercise
   // verify
   assert(v.x == numeric_limits<double>::max());
   assert(v.y == numeric_limits<double>::max());
}  // breakdown

void TestVector::UpperEdgeCase::test_assignment() const
{  // setup
   Vector v1(numeric_limits<double>::max(), numeric_limits<double>::max());
   Vector vCopy = v1;
   // exercise
   // verify
   assert(vCopy.x == numeric_limits<double>::max());
   assert(vCopy.y == numeric_limits<double>::max());
}  // breakdown

void TestVector::UpperEdgeCase::test_copy_constructor() const
{  // setup
   Vector v1(numeric_limits<double>::max(), numeric_limits<double>::max());
   Vector vCopy(v1);
   // exercise
   // verify
   assert(vCopy.x == numeric_limits<double>::max());
   assert(vCopy.y == numeric_limits<double>::max());
}  // breakdown


/********************
 * Getters
 ********************/
// test getX
void TestVector::UpperEdgeCase::testGetX() const
{  // setup
   Vector v(numeric_limits<double>::max(), numeric_limits<double>::max());
   // exercise
   // verify
   assert(v.getX() == numeric_limits<double>::max());
}  // breakdown

// test getY
void TestVector::UpperEdgeCase::testGetY() const
{  // setup
   Vector v(numeric_limits<double>::max(), numeric_limits<double>::max());
   // exercise
   // verify
   assert(v.getY() == numeric_limits<double>::max());
}  // breakdown


/********************
 * Setters
 ********************/
// test setX
void TestVector::UpperEdgeCase::testSetX() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setX(numeric_limits<double>::max());
   // verify
   assert(v.x == numeric_limits<double>::max());
   assert(v.y == -5);
}  // breakdown

// test setY
void TestVector::UpperEdgeCase::testSetY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setY(numeric_limits<double>::max());
   // verify
   assert(v.x == 2);
   assert(v.y == numeric_limits<double>::max());
}  // breakdown

// test set(x, y)
void TestVector::UpperEdgeCase::testSetXY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.set(numeric_limits<double>::max(), numeric_limits<double>::max());
   // verify
   assert(v.x == numeric_limits<double>::max());
   assert(v.y == numeric_limits<double>::max());
}  // breakdown

// test set(s)
void TestVector::UpperEdgeCase::testSetS() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.set(Vector(numeric_limits<double>::max(), numeric_limits<double>::max()));
   // verify
   assert(v.x == numeric_limits<double>::max());
   assert(v.y == numeric_limits<double>::max());
}  // breakdown


/********************
 * Adders
 ********************/
// test addX
void TestVector::UpperEdgeCase::testAddX() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addX(numeric_limits<double>::max());
   // verify
   assert(v.x == 2 + numeric_limits<double>::max()); // error?
   assert(v.y == -5);
}  // breakdown

// test addY
void TestVector::UpperEdgeCase::testAddY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addY(numeric_limits<double>::max());
   // verify
   assert(v.x == 2);
   assert(v.y == -5 + numeric_limits<double>::max());
}  // breakdown

// test add(x, y)
void TestVector::UpperEdgeCase::testAddXY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.add(numeric_limits<double>::max(), numeric_limits<double>::max());
   // verify
   assert(v.x == 2 + numeric_limits<double>::max()); // error?
   assert(v.y == -5 + numeric_limits<double>::max());
}  // breakdown

// test add(s)
void TestVector::UpperEdgeCase::testAddS() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.add(Vector(numeric_limits<double>::max(), numeric_limits<double>::max()));
   // verify
   assert(v.x == 2 + numeric_limits<double>::max()); // error?
   assert(v.y == -5 + numeric_limits<double>::max());
}  // breakdown

/********************
 * Other Getters/Setters
 ********************/
// test getMagnitude
void TestVector::UpperEdgeCase::testGetMagnitude() const
{  // setup
   Vector v(numeric_limits<double>::max(), numeric_limits<double>::max());
   // exercise
   // verify
   assert(v.getMagnitude() == sqrt(pow(numeric_limits<double>::max(), 2) + pow(numeric_limits<double>::max(), 2))); // error?
}  // breakdown

// test getAngleRadians
void TestVector::UpperEdgeCase::testGetAngleRadians() const
{  // setup
   Vector v(numeric_limits<double>::max(), numeric_limits<double>::max());
   // exercise
   // verify
   assert(v.getAngleRadians() == M_PI/4);
}  // breakdown

// test angle
void TestVector::UpperEdgeCase::testAngle() const
{  // setup
   Vector v(numeric_limits<double>::max(), numeric_limits<double>::max());
   // exercise
   // verify
   assert(v.angle() == M_PI/4);
}  // breakdown

// test setPolar
void TestVector::UpperEdgeCase::testSetPolar() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setPolar(numeric_limits<double>::max(), numeric_limits<double>::max());
   // verify
   assert(v.x == numeric_limits<double>::max() * sin(numeric_limits<double>::max()));
   assert(v.y == numeric_limits<double>::max() * cos(numeric_limits<double>::max()));
}  // breakdown

// test setMagnitude
void TestVector::UpperEdgeCase::testSetMagnitude() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setMagnitude(numeric_limits<double>::max(), numeric_limits<double>::max());
   // verify
   assert(v.x == numeric_limits<double>::max() * sin(numeric_limits<double>::max()));
   assert(v.y == numeric_limits<double>::max() * cos(numeric_limits<double>::max()));
}  // breakdown

// test addPolar
void TestVector::UpperEdgeCase::testAddPolar() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addPolar(numeric_limits<double>::max(), numeric_limits<double>::max());
   // verify
   assert(v.x == 2 + numeric_limits<double>::max() * sin(numeric_limits<double>::max())); // error?
   assert(v.y == -5 + numeric_limits<double>::max() * cos(numeric_limits<double>::max()));
}  // breakdown

// test addMagnitude
void TestVector::UpperEdgeCase::testAddMagnitude() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addMagnitude(numeric_limits<double>::max(), numeric_limits<double>::max());
   // verify
   assert(v.x == 2 + numeric_limits<double>::max() * sin(numeric_limits<double>::max())); // error?
   assert(v.y == -5 + numeric_limits<double>::max() * cos(numeric_limits<double>::max()));
}  // breakdown
