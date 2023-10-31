/**********************************************************************
 * testVelocity.h
 * orbitSimulator
 **********************************************************************/

#pragma once
#include "vector.h"

class TestVelocity {
public:
   void run()
   {
      testMultiplyOperator();
   }

private:
   void testMultiplyOperator() const
   {  // setup
      Velocity v(5, 4);
      double dt = .5;
      // exercise
      auto p = v * dt;
      // verify
      assert(typeid(v) == typeid(Velocity));
      assert(typeid(p) == typeid(Position));
      assert(p.getX() == 2.5);
      assert(p.getY() == 2.0);
   }  // breakdown
};
