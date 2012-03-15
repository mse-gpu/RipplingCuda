#ifndef TEST_HELLO_JUNIT_H
#define TEST_HELLO_JUNIT_H

#include "cpptest.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class TestHelloJunit: public Test::Suite
    {
    public:

	TestHelloJunit(void);

    private:

	void testDeviceInfo(void);
	void testHello(void);

    };

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

