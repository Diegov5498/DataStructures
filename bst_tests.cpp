#include <iostream>
#include <vector>
#include "BinarySearchTree.hh"

// Assertion function
bool assertCondition(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "Assertion failed: " << message << std::endl;
        return false;
    }
    return true;
}

int main() {
    // Test insertion and search
    {
        BinarySearchTree bst;
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(2);
        bst.insert(4);
        bst.insert(6);
        bst.insert(8);

        bool allTestsPassed = true;

        allTestsPassed &= assertCondition(bst.search(5), "Search for value 5 failed");
        allTestsPassed &= assertCondition(bst.search(3), "Search for value 3 failed");
        allTestsPassed &= assertCondition(bst.search(7), "Search for value 7 failed");
        allTestsPassed &= assertCondition(bst.search(2), "Search for value 2 failed");
        allTestsPassed &= assertCondition(bst.search(4), "Search for value 4 failed");
        allTestsPassed &= assertCondition(bst.search(6), "Search for value 6 failed");
        allTestsPassed &= assertCondition(bst.search(8), "Search for value 8 failed");

        allTestsPassed &= assertCondition(!bst.search(10), "Search for value 10 (nonexistent) failed");

        if (allTestsPassed) {
            std::cout << "Insertion and Search tests passed!" << std::endl;
        }
    }

    // Test removal
    {
        BinarySearchTree bst;
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(2);
        bst.insert(4);
        bst.insert(6);
        bst.insert(8);

        bst.remove(3); // Remove node with value 3

        bool allTestsPassed = true;

        allTestsPassed &= assertCondition(!bst.search(3), "Search for removed value 3 failed");
        allTestsPassed &= assertCondition(bst.search(2), "Search for value 2 failed after removal");
        allTestsPassed &= assertCondition(bst.search(4), "Search for value 4 failed after removal");

        if (allTestsPassed) {
            std::cout << "Removal test passed!" << std::endl;
        }
    }

    // Test getSize() function
    {
        BinarySearchTree bst;
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(2);
        bst.insert(4);
        bst.insert(6);
        bst.insert(8);

        bool allTestsPassed = true;

        allTestsPassed &= assertCondition(bst.getSize() == 7, "Incorrect size of BST");

        if (allTestsPassed) {
            std::cout << "getSize() function test passed!" << std::endl;
        }
    }

    //Test constructor with vector parameter
    const std::vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    BinarySearchTree bstVector(values);

    bool allTestsPassed = true;

    for (int value : values) {
        allTestsPassed &= assertCondition(bstVector.search(value), "Search for value " + std::to_string(value) + " failed");
    }

    if (allTestsPassed) {
        std::cout << "Constructor with vector parameter test passed!" << std::endl;
    }
    
    return 0;
}
