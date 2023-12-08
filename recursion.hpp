//
//  recursion.hpp
//  DSA
//
//  Created by Joseph Rodgers on 11/30/23.
//

#ifndef recursion_hpp
#define recursion_hpp

#include <stdio.h>

// Recursion study
int recursiveSum(int n);  // Sum
int iterativeSum(int n);
int factorialRecursive(int n);  // Factorial
int factorialIterative(int n);
int powRecursive(int m, int n);  // Power
int powIterative(int m, int n);
int powRecursiveEfficient(int m, int n); // Efficient Power
double taylorSeriesRecursive(int x, int n); // Taylor Series
double efficientTaylorHornersRecursive(int x, int n); // Efficient Horner's taylor series

// Fibonacci
int basicFibRecursive(int n);  // O(2^n)
int basicFibLoop(int n);  // O(n)
int memorizationFibRecursive(int n);  // O(n)

// Combination
int iterative_nCr(int n, int r);
int recursive_nCr(int n, int r);

// Tower of Hanoi
void ToH(int numDisks, int A, int B, int C);
#endif /* recursion_hpp */
