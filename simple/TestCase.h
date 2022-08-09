
#ifndef CPP_UNIT_EXAMPLETESTCASE_H
#define CPP_UNIT_EXAMPLETESTCASE_H

#include <cppunit/extensions/HelperMacros.h>


/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class TestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( TestCase );
  
  CPPUNIT_TEST( TC001 );
  CPPUNIT_TEST( TC002 );
  
  CPPUNIT_TEST_SUITE_END();

protected:
  double m_value1;
  double m_value2;

public:
  void setUp();

protected:
  
  void TC001();
  void TC002();
  
};


#endif
