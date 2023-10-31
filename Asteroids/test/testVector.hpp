/**********************************************************************
 * testVector.h
 * orbitSimulator
 **********************************************************************/


#pragma once

#include <iostream>
#include "vector.h"
#include <cassert>
#include <limits>

using namespace std;

class TestVector
{
public:
   void run()
   {
      ZerosTestCase().run();
      OtherTestCase().run();
      UpperEdgeCase().run();
      LowerEdgeCase().run();
   }

   class ZerosTestCase {
   public:
      void run()
      {
         test_default_constructor();
         test_nondefault_Constructor();
         test_assignment();
         test_copy_constructor();

         testGetX();
         testGetY();
         testSetX();
         testSetY();
         testSetXY();
         testSetS();
         testAddX();
         testAddY();
         testAddXY();
         testAddS();
         testPlus();
         testPlusEquals();
         testGetMagnitude();
         testGetAngleRadians();
         testAngle();
         testSetPolar();
         testSetMagnitude();
         testAddPolar();
         testAddMagnitude();
      }

   private:
      void test_default_constructor() const;
      void test_nondefault_Constructor() const;
      void test_assignment() const;
      void test_copy_constructor() const;

      void testGetX() const;
      void testGetY() const;

      void testSetX() const;
      void testSetY() const;
      void testSetXY() const;
      void testSetS() const;

      void testAddX() const;
      void testAddY() const;
      void testAddXY() const;
      void testAddS() const;

      void testPlus() const;
      void testPlusEquals() const;

      void testGetMagnitude() const;
      void testGetAngleRadians() const;
      void testAngle() const;
      void testSetPolar() const;
      void testSetMagnitude() const;
      void testAddPolar() const;
      void testAddMagnitude() const;
   };

   class OtherTestCase {
   public:
      void run()
      {
         test_default_constructor();
         test_nondefault_Constructor();
         test_assignment();
         test_copy_constructor();

         testGetX();
         testGetY();
         testSetX();
         testSetY();
         testSetXY();
         testSetS();
         testAddX();
         testAddY();
         testAddXY();
         testAddS();
         testPlus();
         testPlusEquals();
         testGetMagnitude();
         testGetAngleRadians();
         testAngle();
         testSetPolar();
         testSetMagnitude();
         testAddPolar();
         testAddMagnitude();
      }

   private:
      void test_default_constructor() const;
      void test_nondefault_Constructor() const;
      void test_assignment() const;
      void test_copy_constructor() const;

      void testGetX() const;
      void testGetY() const;

      void testSetX() const;
      void testSetY() const;
      void testSetXY() const;
      void testSetS() const;

      void testAddX() const;
      void testAddY() const;
      void testAddXY() const;
      void testAddS() const;

      void testPlus() const;
      void testPlusEquals() const;

      void testGetMagnitude() const;
      void testGetAngleRadians() const;
      void testAngle() const;
      void testSetPolar() const;
      void testSetMagnitude() const;
      void testAddPolar() const;
      void testAddMagnitude() const;
   };

   class UpperEdgeCase {
   public:
      void run()
      {
         test_default_constructor();
         test_nondefault_Constructor();
         test_assignment();
         test_copy_constructor();

         testGetX();
         testGetY();
         testSetX();
         testSetY();
         testSetXY();
         testSetS();
         // testAddX(); // we want these to throw errors. how do we handle this?
         testAddY();
         // testAddXY(); // (the error here is double_max + positive_amount will be negative, which doesn't make sense)
         // testAddS(); // error
         // testPlus();
         // testPlusEquals();
         // testGetMagnitude(); // error? we have to have double_max^2 in answer calculation
         testGetAngleRadians();
         testAngle();
         testSetPolar();
         testSetMagnitude();
         // testAddPolar(); // error
         // testAddMagnitude(); // error
      }

   private:
      void test_default_constructor() const;
      void test_nondefault_Constructor() const;
      void test_assignment() const;
      void test_copy_constructor() const;

      void testGetX() const;
      void testGetY() const;

      void testSetX() const;
      void testSetY() const;
      void testSetXY() const;
      void testSetS() const;

      void testAddX() const;
      void testAddY() const;
      void testAddXY() const;
      void testAddS() const;

      void testPlus() const;
      void testPlusEquals() const;

      void testGetMagnitude() const;
      void testGetAngleRadians() const;
      void testAngle() const;
      void testSetPolar() const;
      void testSetMagnitude() const;
      void testAddPolar() const;
      void testAddMagnitude() const;
   };

   class LowerEdgeCase {
   public:
      void run()
      {
         test_default_constructor();
         test_nondefault_Constructor();
         test_assignment();
         test_copy_constructor();

         testGetX();
         testGetY();
         testSetX();
         testSetY();
         testSetXY();
         testSetS();
         // testAddX(); // we want these to throw errors. how do we handle this?
         testAddY();
         // testAddXY(); // (the error here is double_max + positive_amount will be negative, which doesn't make sense)
         // testAddS(); // error
         // testPlus();
         // testPlusEquals();
         // testGetMagnitude(); // error? we have to have double_max^2 in answer calculation
         testGetAngleRadians();
         testAngle();
         testSetPolar();
         testSetMagnitude();
         // testAddPolar(); // error
         // testAddMagnitude(); // error
      }

   private:
      void test_default_constructor() const;
      void test_nondefault_Constructor() const;
      void test_assignment() const;
      void test_copy_constructor() const;

      void testGetX() const;
      void testGetY() const;

      void testSetX() const;
      void testSetY() const;
      void testSetXY() const;
      void testSetS() const;

      void testAddX() const;
      void testAddY() const;
      void testAddXY() const;
      void testAddS() const;

      void testPlus() const;
      void testPlusEquals() const;

      void testGetMagnitude() const;
      void testGetAngleRadians() const;
      void testAngle() const;
      void testSetPolar() const;
      void testSetMagnitude() const;
      void testAddPolar() const;
      void testAddMagnitude() const;
   };
};
