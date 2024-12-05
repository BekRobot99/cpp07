#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        // Test default constructor
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Test parameterized constructor
        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;

        // Populate the array
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }

        // Display array contents
        std::cout << "Int array contents: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Test copy constructor
        Array<int> copiedArray(intArray);
        std::cout << "Copied array contents: ";
        for (unsigned int i = 0; i < copiedArray.size(); i++) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        // Test assignment operator
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned array contents: ";
        for (unsigned int i = 0; i < assignedArray.size(); i++) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;

        // Modify the original array and verify copies are unaffected
        intArray[0] = 100;
        std::cout << "Modified original array first element: " << intArray[0] << std::endl;
        std::cout << "Copied array first element: " << copiedArray[0] << std::endl;

        // Test out-of-bounds access
        std::cout << "Attempting out-of-bounds access..." << std::endl;
        std::cout << intArray[10] << std::endl; // This will throw an exception

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
