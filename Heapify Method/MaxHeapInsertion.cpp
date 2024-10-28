#include <iostream>
#include <vector>
using namespace std;

// Function to perform heapify-up (bubble-up)
void heapifyUp(vector<int>& heap, int index) {
    // Continue while the index is not the root and the current node is greater than its parent
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        
        // If the current node is greater than its parent, swap them
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex; // Move to the parent index
        } else {
            break; // The heap property is satisfied
        }
    }
}

// Function to insert a new value into the max heap
void insertMaxHeap(vector<int>& heap, int value) {
    // Step 1: Add the new element at the end of the heap
    heap.push_back(value);

    // Step 2: Heapify-up to maintain the max heap property
    heapifyUp(heap, heap.size() - 1);
}

// Function to print the heap
void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> maxHeap;

    // Insert elements into the max heap
    insertMaxHeap(maxHeap, 10);
    insertMaxHeap(maxHeap, 20);
    insertMaxHeap(maxHeap, 15);
    insertMaxHeap(maxHeap, 30);
    insertMaxHeap(maxHeap, 40);

    cout << "Max Heap: ";
    printHeap(maxHeap);

    return 0;
}
