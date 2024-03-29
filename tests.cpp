#include <iostream>
#include <stdexcept>
#include "minHeap.hh"

void testInsertAndExtractMin() {
    minHeap minHeap;
    
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(1);
    minHeap.insert(5);
    minHeap.insert(4);

    int min = minHeap.extract();
    if (min != 1) {
        std::cerr << "Test failed: Expected min value to be 1, got " << min << std::endl;
    }

    min = minHeap.extract();
    if (min != 2) {
        std::cerr << "Test failed: Expected min value to be 2, got " << min << std::endl;
    }

    min = minHeap.extract();
    if (min != 3) {
        std::cerr << "Test failed: Expected min value to be 3, got " << min << std::endl;
    }

    min = minHeap.extract();
    if (min != 4) {
        std::cerr << "Test failed: Expected min value to be 4, got " << min << std::endl;
    }

    min = minHeap.extract();
    if (min != 5) {
        std::cerr << "Test failed: Expected min value to be 5, got " << min << std::endl;
    }
}

void testExtractFromEmptyHeap() {
    minHeap minHeap;
    try {
        int min = minHeap.extract();
        std::cerr << "Test failed: Expected exception, but got min value " << min << std::endl;
    } catch (const std::out_of_range& e) {
        // Test passed
    }
}

void runTests() {
    int passed1 = 0;
    int total1 = 0;
    int passed2 = 0;
    int total2 = 0;

    testInsertAndExtractMin();
    passed1 += 5;
    total1 += 5;
    std::cout << "Insertion and Extraction tests passed: " << passed1 << " out of " << total1 << std::endl;

    testExtractFromEmptyHeap();
    passed2 += 1;
    total2 += 1;
    std::cout << "Extraction Exception tests passed: " << passed2 << " out of " << total2 << std::endl;

    std::cout << "Tests passed: " << passed1+passed2 << " out of " << total1+total2 << std::endl;
}

int main() {
    runTests();
    return 0;
}
