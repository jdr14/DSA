//
//  essential_concepts.hpp
//  DSA
//
//  Created by Joseph Rodgers on 11/21/23.
//

#ifndef essential_concepts_hpp
#define essential_concepts_hpp

#include <stdio.h>
#include <iostream>

void printArray(void);
void printArrayWithPointer(void);
void printDynamicallyAllocatedArrayCPP(void);
void printDynamicallyAllocatedArrayC(void);
void printDataTypeSizes(void);
void printPointerSizes(void);

void resizeArrayC(void);
void resizeArrayCpp(void);

void twoDimArray(void);

void referenceExample(void);
void structurePointer(void);

// Array Passing
void arrayPassingExample(int A[], int size);
int * allocate(int size);
void modifyFibBuf(int * buf, int bufSize);

// Definition of a structure
// Doesnt consume any memory until we declare an object of this type
struct Rectangle
{
    int length;
    int breadth;
};

#endif /* essential_concepts_hpp */
