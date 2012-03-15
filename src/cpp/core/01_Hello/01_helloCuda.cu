// Attention : Extension .cu

#include <iostream>
#include "cudaTools.h"

using std::cout;
using std::endl;

void helloCuda(void);

__global__ static void kernelHello(void);
__device__ static void doSomethingHello(void);

void helloCuda(void)
    {
    cout << endl << "[Hello Cuda]" << endl;

    // Organisation logique hierarchique des threads
    //
    // 		L'architecture logique des threads en cuda est hierarchique sur 3 niveaux:
    //
    //			(Niveau 1) 	D'une grille 2D de blocks.
    //					La dimension de cette grille G est [gridDim.x, gridDim.y]
    //					La dimemsion max d�pend du GPU . Example : [65535,65535,1]
    //					Un block est localis� par 2 index : (blockIdx.x,blockIdx.y)
    //					Cette grille poss�de une m�moire
    //						global
    //						constant
    //
    //			(Niveau 2) 	Chaque block est constitu� d'une matrice3D de threads
    //					La dimension de ce block est [blockDim.x, blockDim.y, blockDim.z]
    //					La dimemsion max d�pend du GPU . Example : [1024,1024,64]
    //					Un thread est localis� par 3 index : (threadIdx.x,threadIdx.y,threadIdx.y)
    //					Un block poss�de une m�moire
    //						shared (petite, rapide, accessible only by thread of block)
    //
    //			(Niveau 3)	Un thread est atomique, ie non decomposable
    //					Un thread poss�de une m�moire
    //						local
    // Terminologie:
    //
    //		blockIdx = blockIndex
    // 		threadIdx = threadIndex
    //
    //
    // Type:
    // 		Dim3 est une structure � 3 champs : (x,y,z)
    // 		Dim3 est utilis� pour repr�senter �
    //			(1) Des index
    //				blockId	(avec z=1 toujours)
    //				threadId
    //			(2)Des dimension
    //				gridDim (avec z=1 toujours)
    //				blockDim
    //

    dim3 blockPerGrid = dim3(1, 1); // ou dim3(1, 1) // mais pas  dim3(1, 1,0)
    dim3 threadPerBlock = dim3(1, 1, 1); // ou dim3(1,1)

    print(blockPerGrid, threadPerBlock);
    assertDimLegal(blockPerGrid, threadPerBlock);

    // 1 block de 1 Thread sur le GPU
kernelHello<<<blockPerGrid,threadPerBlock>>>(); // 1 block de 1 Thread sur le GPU
    // addScalar<<<1,1>>>(a,b,ptrDev_c); // syntaxe simplifi�
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__global__ static void kernelHello(void)
    {
    doSomethingHello();
    }

/**
 * Can be call only by device
 * inliner by nvcc (nvidia compiler)
 */
__device__ void doSomethingHello(void)
    {
    // rien
    }
