/**********************************************************************
 * testForce.h
 * orbitSimulator
 **********************************************************************/

#pragma once

#include <iostream>
#include <cassert>
#include "vector.h"

using namespace std;

class TestForce
{
public:
   void run()
   {
      test_default_constructor();
      test_nondefault_Constructor();
      test_assignment();
      test_copy_constructor();
      test_add_force();
      test_operator_add();
      test_operator_addOnto();
      test_operator_divide();
   }

private:
   void test_default_constructor()
   {  // set up
      Force f;
      // exercise
      // f == new Force;
      // verify
      assert(f.x == 0.0);
      assert(f.y == 0.0);
      // breakdown
   }

   void test_nondefault_Constructor ()
   {  // set up
      auto x = 1.0;
      auto y = 2.0;
      // exercise
      Force f(x, y);
      // verify
      assert(f.x == 1.0);
      assert(f.y == 2.0);
      // breakdown
   }

   void test_assignment()
   {  // set up
      Force f;
      Force newF;
      newF.x = 3.0;
      newF.y = 2.0;
      // exercise
      f = newF;
      // verify
      assert(f.x == 3.0);
      assert(f.y == 2.0);
      assert(newF.x == 3.0);
      assert(newF.y == 2.0);
      // breakdown
   }

   void test_copy_constructor()
   {  // set up
      Force newF;
      newF.x = 3.0;
      newF.y = 2.0;
      // exercise
      Force f(newF);
      // verify
      assert(f.x == 3.0);
      assert(f.y == 2.0);
      assert(newF.x == 3.0);
      assert(newF.y == 2.0);
      // breakdown
   }

   void test_add_force()
   {  // set up
      Force f1;
      Force f2;
      f1.x = 2.0;
      f1.y = 3.0;
      f2.x = 6.0;
      f2.y = 4.0;
      // exercise
      f1.add(f2);
      // verify
      assert(f1.x == 8.0);
      assert(f1.y == 7.0);
      assert(f2.x == 6.0);
      assert(f2.y == 4.0);
      // breakdown
   }

   void test_operator_add()
   {  // set up
      Force f1;
      Force f2;
      Force f3;
      f1.x = 2.0;
      f1.y = 3.0;
      f2.x = 6.0;
      f2.y = 4.0;
      f3.x = 0.0;
      f3.y = 0.0;
      // exercise
      f3 = f1 + f2;
      // verify
      assert(f1.x == 2.0);
      assert(f1.y == 3.0);
      assert(f2.x == 6.0);
      assert(f2.y == 4.0);
      assert(f3.x == 8.0);
      assert(f3.y == 7.0);
      // breakdown
   }

   void test_operator_addOnto()
   {  // set up
      Force f1;
      Force f2;
      f1.x = 2.0;
      f1.y = 3.0;
      f2.x = 6.0;
      f2.y = 4.0;
      // exercise
      f1 += f2;
      // verify
      assert(f1.x == 8.0);
      assert(f1.y == 7.0);
      assert(f2.x == 6.0);
      assert(f2.y == 4.0);
      // breakdown
   }

   void test_operator_divide()
   {  // set up
      Force f;
      f.x = 4.0;
      f.y = 6.0;
      double m = 2.0;
      // exercise
      auto a = f / m;
      // verify
      assert(typeid(a) == typeid(Acceleration));
      assert(a.getX() == 2.0);
      assert(a.getY() == 3.0);
      assert(f.x == 4.0);
      assert(f.y == 6.0);
      // breakdown
   }
};
