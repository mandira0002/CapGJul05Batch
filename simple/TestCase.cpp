#include <cppunit/config/SourcePrefix.h>
#include <cstring>
#include "TestCase.h"
#include <testClass.h>

CPPUNIT_TEST_SUITE_REGISTRATION( TestCase );



void TestCase::TC001()
{
  Test *T1 = new Test(22,33);
  Test T2(33,44);

  
  CPPUNIT_ASSERT_EQUAL( 33, T2.getX() );
  CPPUNIT_ASSERT_EQUAL( 44, T2.getY() );
  
 
  
   
}

void TestCase::TC002()
{
  Test *T1 = new Test(22,33);
  
  int ret = T1->getX();
  ret *= 3;
  T1->setY_X(ret);
  CPPUNIT_ASSERT_EQUAL( 66, T1->getY() );
  CPPUNIT_ASSERT_EQUAL( (22*ret), T1->getRes() );
  
  CPPUNIT_ASSERT( strcmp("Bhima",T1->getName())==0 );
  CPPUNIT_ASSERT(false==T1->getBoolRes());
   
}


void TestCase::setUp()
{
  m_value1 = 2.0;
  m_value2 = 3.0;
}



class FixtureTest : public CPPUNIT_NS::TestFixture
{
};

/*CPPUNIT_TEST_FIXTURE(FixtureTest, testEquals)
{
  CPPUNIT_ASSERT_EQUAL( 12, 12 );
}

CPPUNIT_TEST_FIXTURE(FixtureTest, testAdd)
{
  double result = 2.0 + 2.0;
  CPPUNIT_ASSERT( result == 4.0 );
}
*/