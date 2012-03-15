#include <iostream>
#include "cudaTools.h"

__global__ static void kernelHello(void);
__device__ static void doSomethingHello(void);

extern void launchMandelBrot(void){
    std::cout << "Launch MandelBrot (CUDA Version)" << std::endl << std::endl;

    dim3 blockPerGrid = dim3(1, 1); // ou dim3(1, 1) // mais pas  dim3(1, 1,0)
    dim3 threadPerBlock = dim3(1, 1, 1); // ou dim3(1,1)

    std::cout << "Dimensions" << std::endl;
    print(blockPerGrid, threadPerBlock);

    assertDimLegal(blockPerGrid, threadPerBlock);

    kernelHello<<<blockPerGrid,threadPerBlock>>>();
}

__global__ static void kernelHello(void){
    doSomethingHello();
}

__device__ void doSomethingHello(void){
    // rien
}
