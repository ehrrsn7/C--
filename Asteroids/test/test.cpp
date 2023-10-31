/**********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 **********************************************************************/

#include "test.h"
#include "testVector.h"
#include "testPosition.h"
#include "testVelocity.h"
#include "TestAcceleration.h"
#include "testForce.h"
#include "testGravity.h"
#include "testPhysicsFormulas.h"

/**************************************************
 * TEST RUNNER
 * Runs all the unit tests
 **************************************************/
void testRunner() {
   TestPosition().run();
   // TestVector().run();
   TestVelocity().run();
   TestAcceleration().run();
   // TestForce().run();
   TestGravity().run();
   testPhysicsFormulas();
}
