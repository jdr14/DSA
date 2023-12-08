//
//  recursion.cpp
//  DSA
//
//  Created by Joseph Rodgers on 11/30/23.
//

#include "recursion.hpp"

int recursiveSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return recursiveSum(n - 1) + n;
    }
}
int iterativeSum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int factorialRecursive(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return factorialRecursive(n-1) * n;
    }
}
int factorialIterative(int n)
{
    int s = 1;
    for(int i = 1; i <= n; i++)
    {
        s *= i;
    }
    return s;
}

int powRecursive(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return powRecursive(m, n-1) * m;
    }
}
// For example because we can represent 2^9 as 2 * (2^2)^4
// We can do the following
int powRecursiveEfficient(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    
    if (n % 2 == 0) // even case
    {
        return powRecursiveEfficient(m*m, n/2);
    }
    else
    {
        return m * powRecursiveEfficient(m*m, (n-1)/2);
    }
}
int powIterative(int m, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= m;
    }
    return result;
}

double taylorSeriesRecursive(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = taylorSeriesRecursive(x, n-1);
        p *= x; // power is numerator
        f *= n; // factor is denominator
        return r + p/f;
    }
}

double efficientTaylorHornersRecursive(int x, int n)
{
    static double s;
    if (n == 0)
    {
        return s;
    }
    s *= 1 + x/n;
    return efficientTaylorHornersRecursive(x, n-1);
}

// This recursive function suffers from excessive recursion
int basicFibRecursive(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return basicFibRecursive(n-2) + basicFibRecursive(n-1);
}

int basicFibLoop(int n)
{
    int t1 = 0;
    int t2 = 1;
    int s = 0;
    if (n <= 1)
    {
        return n;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            s = t1 + t2;
            t1 = t2;
            t2 = s;
        }
        return s;
    }
}

/*
The memorization technique uses global array stored in code section to eliminate excessive recursive calls
 */
static int F[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int memorizationFibRecursive(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n-2] == -1) // left child not known yet
            F[n-2] = memorizationFibRecursive(n-2);
        if (F[n-1] == -1) // right child not known yet
            F[n-1] = memorizationFibRecursive(n-1);
        return F[n-2] + F[n-1];
    }
}

// nCr = n! / (r! * (n-r)!)
// Iterative Combination formula
int iterative_nCr(int n, int r)
{
    int num = factorialIterative(n);
    int den = factorialIterative(r) * factorialIterative(n-r);
    return (num / den);
}

// Recursive Combination formula
// Used pascals triangle to map these values.
int recursive_nCr(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return recursive_nCr(n-1, r-1) + recursive_nCr(n-1, r);
}

/* Tower of Hanoi
 To approach a recursive solution, begin by identifying the base case and also the first couple of cases to identify the pattern.  For Tower of Hanoi start by analyzing what we need to do for 1 disk, then 2 disks, then 3 disks.
 1 disk:
    Move disk from Tower A to C using B
        - let A be from tower, B be using tower, C is destination tower represented by TOH(1, A, B, C)
 2 disks:
    TOH(2, A, B, C)
        1. TOH(1, A, B, C); // Use previously defined step
        2. Print "Move disk from A to C using B"
        3. TOH(1, B, A, C); // Move B to C using A
 
 3 disks:
    TOH(n, A, B, C)
        1. TOH(n-1, A, C, B); // Move A to B using C
        2. Print "Move disk from A to C using B"
        3. TOH(n-1, B, A, C); // Move B to C using A
 */
void ToH(int numDisks, int A, int B, int C)
{
    if (numDisks > 0) // If there are no disks, don't do anything
    {
        ToH(numDisks - 1, A, C, B);
        printf("\nfrom %d to %d", A, C);
        ToH(numDisks - 1, B, A, C);
    }
}
