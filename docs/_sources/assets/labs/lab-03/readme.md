# Lab 03: Dynamic Arrays

## Arrays

Arrays are one of the most common and versatile data structures and are essential to almost any useful `C` or `C++` program. They allow us to store hundreds, or even thousands, of elements inside of memory while providing random access in $O(1)$ to all of them. While these helpful structures provide us with near-instant access to our data whenever we need it, they are not without weakness. When using regular C-style arrays, you must declare a fixed size for them at the time of their creation and, once this size is declared, it cannot be changed.

```C++
// this array is limited to a maximum of 100 elements, it CANNOT hold more
int myArray[100];
// this array is dynamically *allocated* but its size is still static
int *myOtherArray = new int[100];
```

This presents an obvious problem: What if you don't know how much space you need in your array at compile time? On one hand, if you declare an array with too little space, you will have nowhere to store additional values. On the other hand, if you always declare an array with maximum capacity (e.g. `ULLONG_MAX` equal to 18446744073709551615) you will almost certainly have enough space, but you will be wasting huge amounts of unused memory in almost any situation.

As it turns out, the solution to the problem of capacity is to use *Dynamic Arrays*.

## Dynamic Arrays (Resizable Arrays)

Dynamic Arrays are similar to regular `C++` arrays in that they still provide random access in constant time to to elements. However, Dynamic Arrays have the advantage of being **dynamically resizable**. This means that they can grow as you add more elements to them and shrink as you no longer need space. Using a Dynamic Array, you don't need to know the size of a list at compile time.

The way a Dynamic Array works is to begin with a starting size (often 0). For every insert, we do one of two things depending on the current state of the array:

```
Array is NOT full:
	insert into our array 
Array IS full:
	allocate memory for new array
	copy data from old array into new array
	delete the old array
```

>If you have programmed previously, chances are you are already familiar with data structures that implement the same idea as dynamic arrays in one language or another. C++ provides an implementation `std::vector<>`. Java's implementation is called an `ArrayList<>`.

The goal of this assignment is to implement your own Dynamic Array Class in `C++`.

## Amortized Analysis

For arrays, it is a simple task to see that an **insert** operation runs in $O(1)$ time. We have random memory access, and all of the space we need is already allocated. It does not matter if we are inserting into index 0, or index 10,000; both operations will take the same amount of time. Most functions are also fairly simple to calculate Big-Oh; just count the instructions.

But what about for a Dynamic Array? Some inserts will take $O(1)$ time, but others will require the above steps to resize of the array $O(n)$. Observe the following series of inserts:

![image](./Dynamic-Table.png)

Any time there is the (Overflow) label, that is saying the array must be resized. How can we calculate the run time for a function (insert) for a function that is sometimes O(1), and sometimes O(n)? Well, we essentially just take the average:

![image](./AmortizedAnalysis.png)

---

## Your Task

In order to implement your own class, we are providing starter code. You will be given a [*header file*](/sp21-archive/labs/lab-03/code/DynamicArray.h) (`DynamicArray.h`) and a partially-implemented [*source file*](/sp21-archive/labs/lab-03/code/DynamicArray.cpp) (`DynamicArray.cpp`) for a class `DynamicArray`.

```c++
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <string>

class DynamicArray {
    private:
        // the number of items currently in the array
        unsigned int m_length; 
        // the number of available spaces in the array
        unsigned int m_capacity; 
        // the scaling factor when resizing the array (always > 1)
        double m_scaling_factor; 
        // pointer to the array of integers
        int *m_data; 

    public:
        // default constructor, capacity = 0, no need to allocate an internal array yet
        DynamicArray(); 
        // default constructor with a scaling factor, creates an array with capacity = capacity
        DynamicArray(double scaling_factor, unsigned int capacity); 
        // fill constructor, creates an array of capacity = length, and set all values to `default_value`
        DynamicArray(double scaling_factor, unsigned int length, int default_value); 
        // copy constructor
        DynamicArray(const DynamicArray& other); 
        // default destructor, free memory of the array here
        ~DynamicArray(); 

        // get the number of elements in the array
        unsigned int getLength(); 
        // get the capacity of the array
        unsigned int getCapacity();
        // get scaling factor Needed by GUI 
        double getScalingFactor();
        // set the scaling factor of the array
        void setScalingFactor(double value); 
        // convert the vector into a printable string in the format "{x x x x}" where x is data in the array
        std::string toString(); 

    	// add a value to the end of the array (resize if necessary)
        void append(int value); 
        // add a value to the beginning of the array (resize if necessary)
        void prepend(int value); 
    
        // find the first occurrence of "value" in the array. Return false if the value is not found
        bool findFirstOf(int value, unsigned int* index);
        // find the last occurrence of "value" in the array. Return false if the value is not found
        bool findLastOf(int value, unsigned int* index); 

        // remove the last value from the array
        void removeLast(); 
        // remove the first value from the array 
        void removeFirst(); 
        // remove all elements from the array 
        // allocated memory should be deleted and the array pointer should now point to NULL
        // capacity and length should be reset to zero
        void clear(); 

        // overloading the [] operator for read/write access
        int& operator[](unsigned int index); 
        // assignment operator
        DynamicArray& operator=(const DynamicArray &other); 
};

#endif
```

```c++
#include "DynamicArray.h"
#include <cstring>

DynamicArray::DynamicArray()
    : m_length(0), m_capacity(0), m_scaling_factor(2.0), m_data(nullptr) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    //..............
    // TODO
    //..............
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    //..............
    // TODO
    //..............
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other; 
}

DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::getLength() {
    return m_length;
}

unsigned int DynamicArray::getCapacity() {
    return m_capacity;
}

double DynamicArray::getScalingFactor() {
    return m_scaling_factor;
}

void DynamicArray::setScalingFactor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::toString() {
    std::string str("{");
    //..............
    // TODO
    //..............
    return str;
}

void DynamicArray::append(int value) {
    //..............
    // TODO
    //..............
}

void DynamicArray::prepend(int value) {
    //..............
    // TODO
    //..............
}

bool DynamicArray::findFirstOf(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............
    return found;
}

bool DynamicArray::findLastOf(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............
    return found;
}

void DynamicArray::removeLast() {
    //..............
    // TODO
    //..............
}

void DynamicArray::removeFirst() {
    //..............
    // TODO
    //..............
}

void DynamicArray::clear() {
    //..............
    // TODO
    //..............
}

int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this); 
}
```

Some functions have already been implemented for you inside of the `DynamicArray.cpp` file. The rest of the functions are up to you to implement, specifically where you see `// TODO` comments. You may add your own **private helper functions** should you wish.

> Note: You are **not** allowed to alter any of the given private variables, public function signatures or implementations.

---

## Requirements

> We **strongly recommend** you complete `toString()` so it's easier to test and visualize your code.

1. Complete `append()` and `prepend()`
2. Complete `findFirstOf()` and `findLastOf()`
3. Complete `removeLast()`, `removeFirst()`, and `clear()`
4. Create test cases for each of your functions that prove they work. Note: The array should **grow/shrink accordingly** with the data!
    - Please **print or check your length and capacity** with each test so you can confirm correct functionality.
