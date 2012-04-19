#include <stdlib.h>

#include "GLUTWindowManagers.h"
#include "RipplingImage.hpp"
#include "ChronoOMPs.h"
#include "cuda_gl_interop.h"

#include "cudaTools.h"
#include "deviceTools.h"

int launchApplication(int argc, char** argv);
int bench(int argc, char** argv);

int main(int argc, char** argv){
    return bench(argc, argv);
    //return launchApplication(argc, argv);
}

int launchApplication(int argc, char** argv){
    if (nbDeviceDetect() >= 1){
    	int deviceId = 2;

    	std::cout << "Launch Rippling in Cuda" << std::endl;

    	HANDLE_ERROR(cudaSetDevice(deviceId)); // active gpu of deviceId
    	HANDLE_ERROR(cudaSetDeviceFlags(cudaDeviceMapHost)); // Not all gpu allow the use of mapMemory (avant prremier appel au kernel)
    	HANDLE_ERROR(cudaGLSetGLDevice(deviceId));

    	GLUTWindowManagers::init(argc, argv);
    	GLUTWindowManagers* glutWindowManager = GLUTWindowManagers::getInstance();

    	int w = 600;
    	int h = 600;

    	GLRipplingImage* image = new GLRipplingImage(w, h);

    	glutWindowManager->createWindow(image);
    	glutWindowManager->runALL(); //Blocking

    	delete image;

    	return EXIT_SUCCESS;
        } else {
    	return EXIT_FAILURE;
        }
}

#define DIM_BENCH 10000

extern void useKernelAnimationHSB(uchar4* ptrDevPixels, int w, int h, float t);

int bench(int argc, char** argv){
    std::cout << "Launch benchmark" << std::endl;

    if (nbDeviceDetect() >= 1){
    	int deviceId = 1;

    	HANDLE_ERROR(cudaSetDevice(deviceId)); // active gpu of deviceId
    	HANDLE_ERROR(cudaSetDeviceFlags(cudaDeviceMapHost)); // Not all gpu allow the use of mapMemory (avant prremier appel au kernel)

    	//Force the driver to run
    	int* fake;
    	HANDLE_ERROR(cudaMalloc((void**) &fake, sizeof(int)));

    	uchar4* image;
    	HANDLE_ERROR(cudaMalloc(&image, DIM_BENCH * DIM_BENCH * sizeof(uchar4)));

    	std::cout << "End of malloc" << std::endl;
    	std::cout << "Size of the image: " << (DIM_BENCH * DIM_BENCH * sizeof(uchar4)) << std::endl;

    	CUevent start;
    	CUevent stop;
    	HANDLE_ERROR(cudaEventCreate(&start, CU_EVENT_DEFAULT));
    	HANDLE_ERROR(cudaEventCreate(&stop, CU_EVENT_DEFAULT));
    	HANDLE_ERROR(cudaEventRecord(start, 0));

    	for(int i = 0; i < 10; ++i){
            useKernelAnimationHSB(image, DIM_BENCH, DIM_BENCH, 1);
    	}

        float elapsed = 0;
    	HANDLE_ERROR(cudaEventRecord(stop, 0));
        HANDLE_ERROR(cudaEventSynchronize(stop));
    	HANDLE_ERROR(cudaEventElapsedTime(&elapsed, start, stop));

        std::cout << "CUDA Version took " << elapsed << "ms" << std::endl;

    	HANDLE_ERROR(cudaEventDestroy(start));
    	HANDLE_ERROR(cudaEventDestroy(stop));

    	HANDLE_ERROR(cudaFree(image));
    	HANDLE_ERROR(cudaFree(fake));

    	return EXIT_SUCCESS;
    } else {
    	return EXIT_FAILURE;
    }
}
