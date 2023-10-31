/**********************************************************************
 * testAcceleration.h
 * orbitSimulator
 **********************************************************************/

#pragma once

#include "vector.h"

class TestAcceleration {
public:
   void run()
   {
      testMultiplyOperator();
   }

private:
   void testMultiplyOperator() const
   {  // setup
      Acceleration a;
      a.x = 5;
      a.y = 4;
      double dt = .5;
      // exercise
      auto v = a * dt;
      // verify
      assert(typeid(a) == typeid(Acceleration));
      assert(typeid(v) == typeid(Velocity));
      assert(v.getX() == 2.5);
      assert(v.getY() == 2.0);
   }  // breakdown
};
