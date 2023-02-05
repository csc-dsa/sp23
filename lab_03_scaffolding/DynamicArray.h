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
        unsigned int get_length();
        // get the capacity of the array
        unsigned int get_capacity();
        // get scaling factor Needed by GUI 
        double get_scaling_factor();
        // set the scaling factor of the array
        void set_scaling_factor(double value);
        // convert the vector into a printable string 
        std::string to_string();

        // find the first occurrence of "value" in the array. Return false if the value is not found
        bool find_first_of(int value, unsigned int* index);
        // find the last occurrence of "value" in the array. Return false if the value is not found
        bool find_last_of(int value, unsigned int* index);

        // add a value to the end of the array (resize if necessary)
        void append(int value); 
        // add a value to the beginning of the array (resize if necessary)
        void prepend(int value); 
        // remove the last value from the array
        void remove_last();
        // remove the first value from the array 
        void remove_first();
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
