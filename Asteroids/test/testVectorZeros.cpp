/**********************************************************************
 * testVectorZeros.cpp
 * orbitSimulator
 **********************************************************************/

#include "testVector.h"

/********************
 * Constructors
 ********************/
void TestVector::ZerosTestCase::test_default_constructor() const
{  // setup
   Vector v;
   // exercise
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

void TestVector::ZerosTestCase::test_nondefault_Constructor () const
{  // setup
   Vector v(0, 0);
   // exercise
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

void TestVector::ZerosTestCase::test_assignment() const
{  // setup
   Vector v1(0, 0);
   Vector vCopy = v1;
   // exercise
   // verify
   assert(vCopy.x == 0);
   assert(vCopy.y == 0);
}  // breakdown

void TestVector::ZerosTestCase::test_copy_constructor() const
{  // setup
   Vector v1(0, 0);
   Vector vCopy(v1);
   // exercise
   // verify
   assert(vCopy.x == 0);
   assert(vCopy.y == 0);
}  // breakdown


/********************
 * Getters
 ********************/
// test getX
void TestVector::ZerosTestCase::testGetX() const
{  // setup
   Vector v(0, 0);
   // exercise
   // verify
   assert(v.getX() == 0);
}  // breakdown

// test getY
void TestVector::ZerosTestCase::testGetY() const
{  // setup
   Vector v(0, 0);
   // exercise
   // verify
   assert(v.getY() == 0);
}  // breakdown


/********************
 * Setters
 ********************/
// test setX
void TestVector::ZerosTestCase::testSetX() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.setX(0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

// test setY
void TestVector::ZerosTestCase::testSetY() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.setY(0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

// test set(x, y)
void TestVector::ZerosTestCase::testSetXY() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.set(0, 0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

// test set(s)
void TestVector::ZerosTestCase::testSetS() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.set(Vector(0, 0));
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown


/********************
 * Adders
 ********************/
// test addX
void TestVector::ZerosTestCase::testAddX() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.addX(0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

// test addY
void TestVector::ZerosTestCase::testAddY() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.addY(0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

// test add(x, y)
void TestVector::ZerosTestCase::testAddXY() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.add(0, 0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

// test add(s)
void TestVector::ZerosTestCase::testAddS() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.add(Vector(0, 0));
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

/********************
 * Operators
 ********************/
void TestVector::ZerosTestCase::testPlus() const
{  // setup
   Vector v(0, 0);
   // exercise
   Vector newV = v + Vector(0, 0);
   // verify
   assert(newV.x == 0);
   assert(newV.y == 0);
}  // breakdown

void TestVector::ZerosTestCase::testPlusEquals() const
{  // setup
   Vector v(0, 0);
   // exercise
   v += Vector(0, 0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

/********************
 * Other Getters/Setters
 ********************/
// test getMagnitude
void TestVector::ZerosTestCase::testGetMagnitude() const
{  // setup
   Vector v(0, 0);
   // exercise
   // verify
   assert(v.getMagnitude() == 0);
}  // breakdown

// test getAngleRadians
void TestVector::ZerosTestCase::testGetAngleRadians() const
{  // setup
   Vector v(0, 0);
   // exercise
   // verify
   assert(v.getAngleRadians() == 0);
}  // breakdown

// test angle
void TestVector::ZerosTestCase::testAngle() const
{  // setup
   Vector v(0, 0);
   // exercise
   // verify
   assert(v.angle() == 0);
}  // breakdown

// test setPolar
void TestVector::ZerosTestCase::testSetPolar() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.setPolar(0, 0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

// test setMagnitude
void TestVector::ZerosTestCase::testSetMagnitude() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.setMagnitude(0, 0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

// test addPolar
void TestVector::ZerosTestCase::testAddPolar() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.addPolar(0, 0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

// test addMagnitude
void TestVector::ZerosTestCase::testAddMagnitude() const
{  // setup
   Vector v(0, 0);
   // exercise
   v.addMagnitude(0, 0);
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown
