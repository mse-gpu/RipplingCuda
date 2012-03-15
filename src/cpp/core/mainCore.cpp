#include <iostream>
#include <stdlib.h>

#include "deviceTools.h"

using std::cout;
using std::endl;

extern void helloCuda(void);

int mainCore(void);

bool useHello(void){
    helloCuda();
    return true;
}

int mainCore(void)
    {
    //printAllDeviceProp();

    bool isOk = true;
    //isOk &= useHello();
    isOk &= useHello();

    cout<<"\n-------------------------"<<endl;
    cout << "\nisOK = " << isOk << endl;
    cout<<"\nEnd : mainCore"<<endl;

    return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
    }
