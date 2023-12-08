//
//  template_class_example.hpp
//  DSA
//
//  Created by Joseph Rodgers on 11/28/23.
//

#ifndef template_class_example_hpp
#define template_class_example_hpp

#include <stdio.h>

// Template class example (to take generic data types)
template<class T>
class Arithmetic
{
private:
    T a;
    T b;
public:
    Arithmetic();
    Arithmetic(T a, T b);
    T add();
    void set(T a, T b);
    T sub();
    
    // Destructor used for freeing dynamically allocated memory
    ~Arithmetic();
};


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
    std::cout << "destructor\n" << std::endl;
}

#endif /* template_class_example_hpp */
