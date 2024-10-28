#include <iostream>
#include <vector>
using namespace std;

// Function to perform heapify-up (bubble-up) for min heap
void heapifyUp(vector<int>& heap, int index) {
    // Continue while the index is not the root and the current node is smaller than its parent
    while (index > 1) {  // Start checking from index 1 for a 1-based index array
        int parentIndex = index / 2;

        // If the current node is smaller than its parent, swap them
        if (heap[index] < heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex; // Move to the parent index
        } else {
            break; // The heap property is satisfied
        }
    }
}

// Function to insert a new value into the min heap
void insertMinHeap(vector<int>& heap, int value) {
    // Step 1: Add the new element at the end of the heap
    heap.push_back(value);

    // Step 2: Heapify-up to maintain the min heap property
    heapifyUp(heap, heap.size() - 1);
}

// Function to print the heap
void printHeap(const vector<int>& heap) {
    // Start from index 1 to print the 1-based index heap
    for (int i = 1; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> minHeap;
    minHeap.push_back(-1);  // Placeholder for 1-based indexing

    // Insert elements into the min heap
    insertMinHeap(minHeap, 30);
    insertMinHeap(minHeap, 20);
    insertMinHeap(minHeap, 15);
    insertMinHeap(minHeap, 10);
    insertMinHeap(minHeap, 5);

    cout << "Min Heap: ";
    printHeap(minHeap);

    return 0;
}
