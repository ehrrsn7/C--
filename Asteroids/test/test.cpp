/**********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 **********************************************************************/

#include "test.hpp"
#include "testVector.hpp"
#include "testPosition.hpp"
#include "testVelocity.hpp"
#include "TestAcceleration.hpp"
#include "testForce.hpp"
#include "testGravity.hpp"
#include "testPhysicsFormulas.hpp"

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
