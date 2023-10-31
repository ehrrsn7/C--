/**********************************************************************
 * testVectorLower.cpp
 * orbitSimulator
 **********************************************************************/

#include "testVector.h"

/********************
 * Constructors
 ********************/
void TestVector::LowerEdgeCase::test_default_constructor() const
{  // setup
   Vector v;
   // exercise
   // verify
   assert(v.x == 0);
   assert(v.y == 0);
}  // breakdown

void TestVector::LowerEdgeCase::test_nondefault_Constructor () const
{  // setup
   Vector v(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // exercise
   // verify
   assert(v.x == std::numeric_limits<double>::lowest());
   assert(v.y == std::numeric_limits<double>::lowest());
}  // breakdown

void TestVector::LowerEdgeCase::test_assignment() const
{  // setup
   Vector v1(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   Vector vCopy = v1;
   // exercise
   // verify
   assert(vCopy.x == std::numeric_limits<double>::lowest());
   assert(vCopy.y == std::numeric_limits<double>::lowest());
}  // breakdown

void TestVector::LowerEdgeCase::test_copy_constructor() const
{  // setup
   Vector v1(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   Vector vCopy(v1);
   // exercise
   // verify
   assert(vCopy.x == std::numeric_limits<double>::lowest());
   assert(vCopy.y == std::numeric_limits<double>::lowest());
}  // breakdown


/********************
 * Getters
 ********************/
// test getX
void TestVector::LowerEdgeCase::testGetX() const
{  // setup
   Vector v(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // exercise
   // verify
   assert(v.getX() == std::numeric_limits<double>::lowest());
}  // breakdown

// test getY
void TestVector::LowerEdgeCase::testGetY() const
{  // setup
   Vector v(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // exercise
   // verify
   assert(v.getY() == std::numeric_limits<double>::lowest());
}  // breakdown


/********************
 * Setters
 ********************/
// test setX
void TestVector::LowerEdgeCase::testSetX() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setX(std::numeric_limits<double>::lowest());
   // verify
   assert(v.x == std::numeric_limits<double>::lowest());
   assert(v.y == -5);
}  // breakdown

// test setY
void TestVector::LowerEdgeCase::testSetY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setY(std::numeric_limits<double>::lowest());
   // verify
   assert(v.x == 2);
   assert(v.y == std::numeric_limits<double>::lowest());
}  // breakdown

// test set(x, y)
void TestVector::LowerEdgeCase::testSetXY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.set(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // verify
   assert(v.x == std::numeric_limits<double>::lowest());
   assert(v.y == std::numeric_limits<double>::lowest());
}  // breakdown

// test set(s)
void TestVector::LowerEdgeCase::testSetS() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.set(Vector(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest()));
   // verify
   assert(v.x == std::numeric_limits<double>::lowest());
   assert(v.y == std::numeric_limits<double>::lowest());
}  // breakdown


/********************
 * Adders
 ********************/
// test addX
void TestVector::LowerEdgeCase::testAddX() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addX(std::numeric_limits<double>::lowest());
   // verify
   assert(v.x == 2 + std::numeric_limits<double>::lowest()); // error?
   assert(v.y == -5);
}  // breakdown

// test addY
void TestVector::LowerEdgeCase::testAddY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addY(std::numeric_limits<double>::lowest());
   // verify
   assert(v.x == 2);
   assert(v.y == -5 + std::numeric_limits<double>::lowest());
}  // breakdown

// test add(x, y)
void TestVector::LowerEdgeCase::testAddXY() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.add(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // verify
   assert(v.x == 2 + std::numeric_limits<double>::lowest()); // error?
   assert(v.y == -5 + std::numeric_limits<double>::lowest());
}  // breakdown

// test add(s)
void TestVector::LowerEdgeCase::testAddS() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.add(Vector(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest()));
   // verify
   assert(v.x == 2 + std::numeric_limits<double>::lowest()); // error?
   assert(v.y == -5 + std::numeric_limits<double>::lowest());
}  // breakdown

/********************
   * Other Getters/Setters
   ********************/
// test getMagnitude
void TestVector::LowerEdgeCase::testGetMagnitude() const
{  // setup
   Vector v(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // exercise
   // verify
   assert(v.getMagnitude() == sqrt(pow(std::numeric_limits<double>::lowest(), 2) + pow(std::numeric_limits<double>::lowest(), 2))); // error?
}  // breakdown

// test getAngleRadians
void TestVector::LowerEdgeCase::testGetAngleRadians() const
{  // setup
   Vector v(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // exercise
   // verify
   assert(v.getAngleRadians() == -3 * M_PI/4);
}  // breakdown

// test angle
void TestVector::LowerEdgeCase::testAngle() const
{  // setup
   Vector v(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // exercise
   // verify
   assert(v.angle() == M_PI/4);
}  // breakdown

// test setPolar
void TestVector::LowerEdgeCase::testSetPolar() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setPolar(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // verify
   assert(v.x == std::numeric_limits<double>::lowest() * sin(std::numeric_limits<double>::lowest()));
   assert(v.y == std::numeric_limits<double>::lowest() * cos(std::numeric_limits<double>::lowest()));
}  // breakdown

// test setMagnitude
void TestVector::LowerEdgeCase::testSetMagnitude() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.setMagnitude(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // verify
   assert(v.x == std::numeric_limits<double>::lowest() * sin(std::numeric_limits<double>::lowest()));
   assert(v.y == std::numeric_limits<double>::lowest() * cos(std::numeric_limits<double>::lowest()));
}  // breakdown

// test addPolar
void TestVector::LowerEdgeCase::testAddPolar() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addPolar(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // verify
   assert(v.x == 2 + std::numeric_limits<double>::lowest() * sin(std::numeric_limits<double>::lowest())); // error?
   assert(v.y == -5 + std::numeric_limits<double>::lowest() * cos(std::numeric_limits<double>::lowest()));
}  // breakdown

// test addMagnitude
void TestVector::LowerEdgeCase::testAddMagnitude() const
{  // setup
   Vector v(2, -5);
   // exercise
   v.addMagnitude(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());
   // verify
   assert(v.x == 2 + std::numeric_limits<double>::lowest() * sin(std::numeric_limits<double>::lowest())); // error?
   assert(v.y == -5 + std::numeric_limits<double>::lowest() * cos(std::numeric_limits<double>::lowest()));
}  // breakdown
