#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array {
private:
    T* _elements;           // Pointer to the array of elements
    unsigned int _size;     // Number of elements in the array

public:
    // Default constructor: Creates an empty array
    Array() : _elements(nullptr), _size(0) {}

    // Parameterized constructor: Creates an array of n elements initialized by default
    Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

    // Copy constructor
    Array(const Array& other) : _elements(nullptr), _size(0) {
        *this = other; // Use the assignment operator to copy
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            // Deallocate current elements
            delete[] _elements;

            // Allocate new memory and copy elements
            _size = other._size;
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _elements[i] = other._elements[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] _elements;
    }

    // Subscript operator for access (throws std::exception if out of bounds)
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return _elements[index];
    }

    // Const version of the subscript operator
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return _elements[index];
    }

    // Size function: Returns the number of elements in the array
    unsigned int size() const {
        return _size;
    }
};

#endif // ARRAY_HPP
