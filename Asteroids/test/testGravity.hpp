/**********************************************************************
 * testGravity.h
 * orbitSimulator
 **********************************************************************/

#pragma once
#include "vector.h"

class TestGravity {
public:
   void run()
   {
      testDivideOperator();
   }

private:
   void testDivideOperator() const
   {  // setup
      Gravity fg;
      fg.x = 5;
      fg.y = 4;
      double m = 2;
      // exercise
      auto a = fg / m;
      // verify
      assert(typeid(fg) == typeid(Gravity));
      assert(typeid(a) == typeid(Acceleration));
      assert(a.getX() == 2.5);
      assert(a.getY() == 2.0);
   }  // breakdown
};
