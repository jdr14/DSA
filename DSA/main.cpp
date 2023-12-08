//
//  main.cpp
//  DSA
//
//  Created by Joseph Rodgers on 11/20/23.
//
/*
 Parameter passing:
    Pass by value (C/C++)
    Pass by address (C/C++)
    Pass by reference (only available in C++)
 
 When using pass by value, function call gets its own stack frame with
 its own formal params allocated in main memory within the stack frame.
 This only gets deleted once the function finishes execution.
 
 void swap(int x, int y); // pass by value
 void swap(int *x, int *y); // pass by address (allocates memory for pointers)
 void swap(int &x, int &y); // pass by reference (only available in C++ - no memory required for references)
 
 - the pass by reference function gets pasted in the caller stack frame vs. pass by value and pass by address which get their own stack frames
 - Use pass by reference only for small functions, not advisable to use call by reference in heavy functions with loops and heavy logic
 
 - Passing an array must only be by address, not by reference or by value
 - You can have an array internal to a structure and pass the structure by value though
 
 - You cannot use for each loop (i.e. for (int x:A)) on a pointer, so this will only work if the array was declared within that function's scope
 */

// Standard libraries
#include <stdio.h>
#include <iostream>

// Project defined files
#include "essential_concepts.hpp"
#include "template_class_example.hpp"
#include "recursion.hpp"

// Control switches
#define ARRAY (1)
#define HEAP (0)
#define CLASS (0)
#define RECURSION (0)

using namespace std;

int main(int argc, const char * argv[]) 
{
#if ARRAY
    printArray();
    printArrayWithPointer();
    printDynamicallyAllocatedArrayCPP();
    printDynamicallyAllocatedArrayC();
    printDataTypeSizes();
    printPointerSizes();
    referenceExample();
    structurePointer();
    resizeArrayC();
    resizeArrayCpp();
    twoDimArray();
#endif // ARRAY
    
#if HEAP // Heap
    int A[5] = {2, 4, 6, 8, 10};
    int size = sizeof(A)/sizeof(int);
    arrayPassingExample(A, size);
    int * buf = allocate(9);
    modifyFibBuf(buf, 9);
    free(buf);
#endif // HEAP

#if CLASS // Class
    Arithmetic<float> ar(10.99, 5.74);
    cout<<"Add "<< ar.add() << endl;
    cout<<"Sub "<< ar.sub() << endl;
#endif // CLASS
    
#if RECURSION // Recursion
    int m = 2, n = 5;
    printf("\n Recursive sum for n=%d is %d\n", n, recursiveSum(n));
    printf(" Iterative sum for n=%d is %d\n", n, iterativeSum(n));
    printf("\n Recursive factorial for n=%d is %d\n", n, factorialRecursive(n));
    printf(" Iterative factorial for n=%d is %d\n", n, factorialIterative(n));
    printf("\n Recursive power function m^n for m=%d, n=%d is %d\n", m, n, powRecursive(m, n));
    printf(" Iterative power function m^n for m=%d, n=%d is %d\n", m, n, powIterative(m, n));
    printf(" Efficient recursive power function m^n for m=%d, n=%d is %d\n", m, n, powRecursiveEfficient(m, n));
    printf(" Taylor series recursive function for x=%d, n=%d is %lf\n", m, n, taylorSeriesRecursive(m, n));
    
    // Fib sequence functions
    int x = 8;
    printf("\n Excessive Fib Recursive for x=%d is %d", x, basicFibRecursive(x));  // O(2^n)
    printf("\n Basic Fib Loop for x=%d is %d", x, basicFibLoop(x));  // O(2^n)
    printf("\n Memorization Fib Recursive for x=%d is %d\n", x, memorizationFibRecursive(x));  // O(2^n)
    
    int r = 2;
    n = 4;
    printf("\n Iterative nCr for n=%d and r=%d is %d", n, r, iterative_nCr(n, r));
    printf("\n Recursive nCr for n=%d and r=%d is %d\n", n, r, recursive_nCr(n, r));
    
    printf("\nTower of Hanoi steps for 3 disks:");
    ToH(3, 1, 2, 3);
    cout << endl;
#endif // RECURSION
    
    return 0;
}
