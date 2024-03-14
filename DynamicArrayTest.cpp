#include <iostream>
#include "DynamicArray.hh"

// Simple assertion macro for testing
#define ASSERT(condition, message) \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " << message << std::endl; \
        return false; \
    }

// Test function for DynamicArray class
bool testDynamicArray() {
    // Your DynamicArray implementation should be included here or included from a header file

    // Test insertAt and getSize functions
    DynamicArray arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.insertAt(10, 1); // Insert 10 at index 1
    ASSERT(arr.getSize() == 4, "getSize failed");
    ASSERT(arr.getNum(1) == 10, "insertAt failed");

    // Test deleteAt function
    arr.deleteAt(1); // Delete value at index 1
    ASSERT(arr.getSize() == 3, "deleteAt failed");
    ASSERT(arr.getNum(1) == 2, "deleteAt failed");

    // Test push_back and pop_back functions
    arr.push_back(4);
    ASSERT(arr.pop_back() == 4, "pop_back failed");
    ASSERT(arr.getSize() == 3, "pop_back failed");

    // All tests passed
    return true;
}

int main() {
    if (testDynamicArray()) {
        std::cout << "All tests passed!" << std::endl;
        return 0;
    } else {
        std::cerr << "Some tests failed!" << std::endl;
        return 1;
    }
}