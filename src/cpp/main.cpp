#include <stdlib.h>

#include "cudaTools.h"
#include "deviceTools.h"

extern void launchMandelBrot(void);

int main(void)
    {
    if (nbDeviceDetect() >= 1)
	{
	int deviceId = 0;

	HANDLE_ERROR(cudaSetDevice(deviceId)); // active gpu of deviceId
	HANDLE_ERROR(cudaSetDeviceFlags(cudaDeviceMapHost)); // Not all gpu allow the use of mapMemory (avant prremier appel au kernel)

	launchMandelBrot();

	return EXIT_SUCCESS;
	}
    else
	{
	return EXIT_FAILURE;
	}
    }
