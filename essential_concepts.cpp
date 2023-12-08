//
//  essential_concepts.cpp
//  DSA
//
//  Created by Joseph Rodgers on 11/21/23.
//

#include "essential_concepts.hpp"

using namespace std;

void printArray(void)
{
    cout << "\nPrint an array" << endl;
    int A[5] = {2, 4, 5}; // last 2 indicies will be populated with 0
    for (int i = 0; i < 5; i++) {
        printf("%i - ", A[i]);
        printf("%p\n", &A[i]);
    }
    
    // All values will be garbage since they don't belong to you
    // int B[5];
    int B[5] = {1,2,3,4,5};
    for (int x:B)
    {
        printf("%i ", x);
    }
    printf("\n");
}

void printArrayWithPointer(void)
{
    cout << "\nPrint an array using pointer" << endl;
    int A[5] = {2, 4, 6, 8, 10};
    // The name of the array var is pointer to the beginning of the memory
    // DONT use &A when pointing to array, if you want to use &, use &A[0]
    int *p;
    p=A;  // Or p = &A[0]
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

void printDynamicallyAllocatedArrayCPP(void)
{
    cout << "\nPrint dynamicaly allocated array in C++" << endl;
    cout << "Remember:" << endl;
    cout << "\tint *p;" << endl;
    cout << "\tp = new int[size];" << endl;
    cout << "\t// Use \"delete [] p\" to free memory" << endl;
    int *p;
    
    // Dynamically allocate buffer of 20 bytes (5 * 4 bytes per int) on the heap
    p = new int[5];
    
    for (int i = 0; i < 5; i++)
    {
        p[i] = i;
        cout << p[i] << " ";
    }
    
    // Need to use this to return the memory to the system
    delete [] p;  // "delete" is used in c++ language
    cout << endl;
}

void printDynamicallyAllocatedArrayC(void)
{
    cout << "\nPrint dynamicaly allocated array in C" << endl;
    cout << "Remember:" << endl;
    cout << "\tint *p;" << endl;
    cout << "\tp = (int *)malloc(5 * sizeof(int));" << endl;
    cout << "\t// Use \"free(p)\" to free memory" << endl;
    
    int *p;
    p = (int *)malloc(5 * sizeof(int));
    
    for (int i = 0; i < 5; i++)
    {
        p[i] = i;
        printf("%i ", p[i]);
    }
    printf("\n");
    
    // Need to use this to return memory to the system
    free(p);  // "free" is used in c language
}

void resizeArrayC(void)
{
    int size = 5;
    int *p = (int *)malloc(size * sizeof(int));
    printf("\n Array of size %d starting address = %u\n {", size, p);
    for (int i = 0; i < size; i++)
    {
        p[i] = i;
        printf("%d, ", p[i]);
    }
    printf("}\n");
    size *= 2;
    int *q = (int *)malloc(size * sizeof(int));
    printf(" Array of size %d starting address = %u\n {", size, q);
    for (int i = 0; i < size/2; i++)
    {
        q[i] = p[i];  // can also use memcopy for this
        printf("%d, ", q[i]);
    }
    printf("}\n");
    free(p); // first free dynamically allocated memory
    p = q; // reassign p to point to newly dynamically allocated memory
    q = nullptr; // set q to null, handle is no longer needed
}

void resizeArrayCpp(void)
{
    int size = 5;
    int *p = new int[size];
    printf("\n Array of size %d starting address = %u\n {", size, p);
    for (int i = 0; i < size; i++)
    {
        p[i] = i;
        printf("%d, ", p[i]);
    }
    printf("}\n");
    size *= 2;
    int *q = new int[size];
    printf(" Array of size %d starting address = %u\n {", size, q);
    for (int i = 0; i < size/2; i++)
    {
        q[i] = p[i];  // can also use memcopy for this
        printf("%d, ", q[i]);
    }
    printf("}\n");
    delete []p; // deallocate heap allocated memory first
    p = q; // reassign p to point to new memory
    
    q = nullptr;
}

void print2DArray(int *Arr[], const int rows, const int cols)
{
    cout << endl;
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", Arr[i][j]);
        }
        cout << endl;
    }
}

/*
 Two dimensional arrays are allocated as 1 contiugous block of memory so
 in reality
 */
void twoDimArray(void)
{
    const int rows = 3, cols = 4;
    cout << endl;
    
    // Method 1 of declaring and initializing 2d array (all created in stack)
    int A[rows][cols] = { {1, 2, 3, 4}, {2, 4, 6, 8}, {3, 6, 9, 12} };
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", A[i][j]);
        }
        cout << endl;
    }
    
    // Method 2 of declaring and initializing 2d array
    int *B[rows]; // Row of pointers created in stack
    for(int i = 0; i < rows; i++)
    {
        // Allocate and copy memory
        B[i] = (int *)malloc(cols * sizeof (int)); // created in heap
        memcpy(B[i], A[i], sizeof(A[i]));
    }
    print2DArray(B, rows, cols);
    
    // Method 3 of declaring and initializing 2d array
    int **C; // Created in stack
    C = (int **)malloc(rows * sizeof(int *)); // Pointers created in heap
    for(int i = 0; i < rows; i++)
    {
        // Allocate and copy memory
        C[i] = (int *)malloc(cols * sizeof (int)); // created in heap
        memcpy(C[i], A[i], sizeof(A[i]));
    }
    print2DArray(C, rows, cols);
}

void printDataTypeSizes(void)
{
    printf("\nInt size %lu\n", sizeof(int));
    printf("Char size %lu\n", sizeof(char));
    printf("Float size %lu\n", sizeof(float));
    printf("Double size %lu\n", sizeof(double));
}

void printPointerSizes(void)
{
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    cout << "\nInt pointer size " << sizeof(p1) << endl;
    cout << "Char pointer size " << sizeof(p2) << endl;
    cout << "Float pointer size " << sizeof(p3) << endl;
    cout << "Double pointer size " << sizeof(p4) << endl;
}

void referenceExample(void)
{
    cout << "\nReference experiments" << endl;
    int a = 10;
    cout << "int a = 10" << endl;
    
    // Reference = another handle/name for same place in memory i.e. 'a'
    // This is a reference, after this line, r = a r++ is a++
    // Reference does not consume memory like pointers,
    int &r = a;
    cout << "int &r = a; // This is a reference" << endl;
    printf("Result: a = %i, r = %i\n", a, r);
    
    a++;
    r++;
    printf("\na++;\nr++;\n");
    printf("Result: a = %i, r = %i\n", a, r);
    
    // The reference r will always refer to a, not b
    int b = 25;
    r = b;
    printf("\nMemory Addresses: \n\t&b = %p\n\t&r = %p\n\t&a = %p\n", &b, &r, &a);
}

void structurePointer(void)
{
    cout << "\nPointer to structure example" << endl;
    
    // Declare and intialize our structure r with some data
    // In C++ 'struct' is not mandatory, but in c programs, it is
    struct Rectangle r = {10, 5};
    Rectangle b = {2, 4};  // This will have an error in C language
    
    // Creating a pointer on the stack (statically)
    struct Rectangle *c;
    c = &r;
    c->length = 11;
    c->breadth = 6;
    cout << c->length << " " << c->breadth << endl;
    
    // The above are declared statically (on the stack)
    // Below is how we can dynamically allocate memory on the heap for the structure
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    
    *p = {9, 4};
    cout << p->length << " " << p->breadth << endl;
    
    // By order of operations, . takes precedence, so we have to dereference using * and wrap that in () before accessing via .
    (*p).length = 3;
    (*p).breadth = 8;
    cout << p->length << " " << p->breadth << endl;
    
    // The standard way of doing this is accessing pointer memory by using ->
    p->length = 2;
    p->breadth = 7;
    cout << p->length << " " << p->breadth << endl;
    
    // Dynamically allocating memory for structure in C++
    struct Rectangle *p2;
    p2 = new Rectangle;
    *p2 = {1, 3};
    cout << p2->length << " " << p2->breadth << endl;
}

/*
 Pass address into this function since we are using pass by address
 
 Caller would invoke this as follows:
 swap(&a, &b);
 */
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/*
 Pass by reference only works in C++
 This has the same performance as pass by address
 x and y formal parameters become "nicknames" for the actual parameters
 so this has the same effect as pass by address
 
 Caller would invoke this as follows:
 swap(a, b);
 */
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

/*
 Arrays can ONLY be passed by address! NOT by reference or value
 */
void arrayPassingExample(int A[], int size) // can also be (int *A) to be generic
{
    int *p = A;
    int count = 0;
    cout << "\n{";
    while (count < size)
    {
        printf("%i, ", p[count]);
        count++;
    }
    cout << "}" << endl;
    printf("Computed Size %i | Detected Size %i\n", size, count);
}

int * allocate(int size)
{
    int * buf = (int *)malloc(size * sizeof(int));
    int * p = new int[size]; // for C++
    printf("Allocated %lu bytes on the heap\n", sizeof(*buf));
    return buf;
}
void modifyFibBuf(int * buf, int bufSize)
{
    int temp;
    int prevTotal = 1;
    int currTotal = 1;
    cout << "\n{";
    for(int i = 0; i < bufSize; i++)
    {
        // Below are 2 different ways of accessing the values of the array
        buf[i] = prevTotal;
        *(buf + i) = prevTotal;
        temp = prevTotal;
        prevTotal = currTotal;
        currTotal += temp;
        printf("%i, ", buf[i]);
    }
    cout << "}\n" << endl;
}

