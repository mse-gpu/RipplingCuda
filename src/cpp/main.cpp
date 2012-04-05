#include <stdlib.h>

#include "GLUTWindowManagers.h"
#include "RipplingImage.hpp"
#include "ChronoOMPs.h"
#include "cuda_gl_interop.h"

#include "cudaTools.h"
#include "deviceTools.h"

int launchApplication(int argc, char** argv);
int bench();

int main(int argc, char** argv){
    return bench();
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

#define DIM_BENCH 500000

extern void useKernelAnimationHSBBench(int w, int h, float t);

int bench(){
    std::cout << "Launch benchmark" << std::endl;

    if (nbDeviceDetect() >= 1){
    	int deviceId = 2;

    	HANDLE_ERROR(cudaSetDevice(deviceId)); // active gpu of deviceId
    	HANDLE_ERROR(cudaSetDeviceFlags(cudaDeviceMapHost)); // Not all gpu allow the use of mapMemory (avant prremier appel au kernel)
    	HANDLE_ERROR(cudaGLSetGLDevice(deviceId));

        ChronoOMPs chronos;
        chronos.start();

    	useKernelAnimationHSBBench(DIM_BENCH, DIM_BENCH, 1);

        chronos.print("CUDA Version");

    	return EXIT_SUCCESS;
    } else {
    	return EXIT_FAILURE;
    }
}
