#include <iostream>
#include <vector>

class minHeap {
    private:
    std::vector<int> heap;          //Heap container
    void heapifyUp(int index);      //Helper function for heap operations up
    void heapifyDown(int index);    //Helper function for heap operations down

    public:
    void insert(int value);         //Function to insert a value into heap
    int extract();                  //Function to extract the top value
    bool isEmpty() const;           //Function to check if the heap is empty

};

void minHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent_index = (index-1)/2;
        if(heap[index] < heap[parent_index]) {
            std::swap(heap[index], heap[parent_index]);
            index = parent_index;
        } else {
            break;
        }
    }
}

void minHeap::heapifyDown(int index) {
    int small = index;
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;
    int size = heap.size();

    if(leftChild < size && heap[leftChild] < heap[small]) {
        small = leftChild;
    }
    if (rightChild < size && heap[rightChild] < heap[small]) {
        small = rightChild;
    }
    if (small != index) {
        std::swap(heap[index], heap[small]);
        heapifyDown(small);
    }
}

void minHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size()-1);
}

int minHeap::extract() {
    if (heap.empty()) {
        throw std::out_of_range("Heap is empty.");
    }

    int minVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return minVal;
}

bool minHeap::isEmpty() const {
    return heap.empty();
}

