#include <stdlib.h>
#include <iostream>

#include "cppTest+.h"
#include "TestHelloJunit.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static bool testALL(void);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainTest(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainTest(void)
    {
    bool isOk = testALL();

    cout<<"\n-------------------------"<<endl;
    cout << "\nisOK = " << isOk << endl;
    cout<<"\nEnd : mainTest"<<endl;

    return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

bool testALL(void)
    {
    Test::Suite testSuite;

    testSuite.add(std::auto_ptr<Test::Suite>(new TestHelloJunit()));

    //return runTestHtml("TestALL_HTML", testSuite); // Attention: html create in working directory!!
    return runTestConsole("TestALL_Console", testSuite);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

