/**********************************************************************
 * testVectorOther.cpp
 * orbitSimulator
 **********************************************************************/

#include "testVector.h"

/********************
 * Constructors
 ********************/
void TestVector::OtherTestCase::test_default_constructor() const
{  // setup
   Vector v;
   // exercise
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

void TestVector::OtherTestCase::test_nondefault_Constructor () const
{  // setup
   Vector v(2, -5);
   // exercise
   // verify
   assert(v.x == 2);
   assert(v.y == -5);
}  // breakdown

void TestVector::OtherTestCase::test_assignment() const
{  // setup
   Vector v1(2, -5);
   Vector vCopy = v1;
   // exercise
   // verify
   assert(vCopy.x == 2);
   assert(vCopy.y == -5);
}  // breakdown

void TestVector::OtherTestCase::test_copy_constructor() const
{  // setup
   Vector v1(2, -5);
   Vector vCopy(v1);
   // exercise
   // verify
   assert(vCopy.x == 2);
   assert(vCopy.y == -5);
}  // breakdown


/********************
 * Getters
 ********************/
// test getX
void TestVector::OtherTestCase::testGetX() const
{  // setup
   Vector v(2, -5);
   // exercise
   // verify
   assert(v.getX() == 2);
}  // breakdown

// test getY
void TestVector::OtherTestCase::testGetY() const
{  // setup
   Vector v(2, -5);
   // exercise
   // verify
   assert(v.getY() == -5);
}  // breakdown


/********************
 * Setters
 ********************/
// test setX
void TestVector::OtherTestCase::testSetX() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setX(7);
   // verify
   assert(v.x == 7);
   assert(v.y == -5);
}  // breakdown

// test setY
void TestVector::OtherTestCase::testSetY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setY(7);
   // verify
   assert(v.x == 2);
   assert(v.y == 7);
}  // breakdown

// test set(x, y)
void TestVector::OtherTestCase::testSetXY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.set(7, 7);
   // verify
   assert(v.x == 7);
   assert(v.y == 7);
}  // breakdown

// test set(s)
void TestVector::OtherTestCase::testSetS() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.set(Vector(7, 7));
   // verify
   assert(v.x == 7);
   assert(v.y == 7);
}  // breakdown


/********************
 * Adders
 ********************/
// test addX
void TestVector::OtherTestCase::testAddX() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addX(7);
   // verify
   assert(v.x == 9);
   assert(v.y == -5);
}  // breakdown

// test addY
void TestVector::OtherTestCase::testAddY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addY(7);
   // verify
   assert(v.x == 2);
   assert(v.y == 2);
}  // breakdown

// test add(x, y)
void TestVector::OtherTestCase::testAddXY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.add(7, 7);
   // verify
   assert(v.x == 9);
   assert(v.y == 2);
}  // breakdown

// test add(s)
void TestVector::OtherTestCase::testAddS() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.add(Vector(7, 7));
   // verify
   assert(v.x == 9);
   assert(v.y == 2);
}  // breakdown

/********************
 * Operators
 ********************/
void TestVector::OtherTestCase::testPlus() const
{  // setup
   Vector v(2, -5);
   // exercise
   Vector newV = v + Vector(7, 7);
   // verify
   assert(newV.x == 9);
   assert(newV.y == 2);
}  // breakdown

void TestVector::OtherTestCase::testPlusEquals() const
{  // setup
   Vector v(2, -5);
   // exercise
   v += Vector(7, 7);
   // verify
   assert(v.x == 9);
   assert(v.y == 2);
}  // breakdown

/********************
 * Other Getters/Setters
 ********************/
// test getMagnitude
void TestVector::OtherTestCase::testGetMagnitude() const
{  // setup
   Vector v(2, -5);
   // exercise
   // verify
   assert(v.getMagnitude() == sqrt(2*2 + -5*-5));
}  // breakdown

// test getAngleRadians
void TestVector::OtherTestCase::testGetAngleRadians() const
{  // setup
   Vector v(2, -5);
   // exercise
   // verify
   assert(v.getAngleRadians() == atan2(2, -5));
}  // breakdown

// test angle
void TestVector::OtherTestCase::testAngle() const
{  // setup
   Vector v(2, -5);
   // exercise
   // verify
   assert(v.angle() == atan2(2, -5));
}  // breakdown

// test setPolar
void TestVector::OtherTestCase::testSetPolar() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setPolar(7, M_PI/3);
   // verify
   assert(v.x == 7 * sin(M_PI/3));
   assert(v.y == 7 * cos(M_PI/3));
}  // breakdown

// test setMagnitude
void TestVector::OtherTestCase::testSetMagnitude() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setMagnitude(7, M_PI/3);
   // verify
   assert(v.x == 7 * sin(M_PI/3));
   assert(v.y == 7 * cos(M_PI/3));
}  // breakdown

// test addPolar
void TestVector::OtherTestCase::testAddPolar() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addPolar(7, M_PI/3);
   // verify
   assert(v.x == 2 + 7 * sin(M_PI/3));
   assert(v.y == -5 + 7 * cos(M_PI/3));
}  // breakdown

// test addMagnitude
void TestVector::OtherTestCase::testAddMagnitude() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addMagnitude(7, M_PI/3);
   // verify
   assert(v.x == 2 + 7 * sin(M_PI/3));
   assert(v.y == -5 + 7 * cos(M_PI/3));
}  // breakdown
