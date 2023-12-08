//
//  template_class_example.cpp
//  DSA
//
//  Created by Joseph Rodgers on 11/28/23.
//

#include <iostream>

#include "template_class_example.hpp"

//using namespace std;

// Template class example
template<class T>
Arithmetic<T>::Arithmetic()
{
    this->a = 0;
    this->b = 0;
}

template<class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template<class T>
T Arithmetic<T>::add()
{
    return a + b;
}

template<class T>
void Arithmetic<T>::set(T a, T b)
{
    this->a = a;
    this->b = b;
}

template<class T>
T Arithmetic<T>::sub()
{
    return a - b;
}

// Would use the destructor to free dynamlically allocated memory
template<class T>
Arithmetic<T>::~Arithmetic()
{
    std::cout << "\ndestructor" << std::endl;
}
