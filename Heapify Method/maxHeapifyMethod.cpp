#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted with node i
// n is the size of the heap, and i is the root of the subtree
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;           // Assume the root is the largest
    int left = 2 * i;          // Left child index (1-based)
    int right = 2 * i + 1;     // Right child index (1-based)

    // If left child exists and is greater than root
    if (left <= n && arr[left] > arr[largest])
        largest = left;

    // If right child exists and is greater than largest so far
    if (right <= n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root, we need to swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root with largest child
        heapify(arr, n, largest);   // Recursively heapify the affected subtree
    }
}

// Heap sort function that sorts the array in ascending order
void heapSort(vector<int>& arr) {
    int n = arr.size() - 1;  // Adjust size for 1-based indexing

    // Step 1: Build a max-heap from the input array
    for (int i = n / 2; i >= 1; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements from the heap one by one to sort the array
    for (int i = n; i > 1; i--) {
        // Move the current root (maximum element) to the end of the array
        swap(arr[1], arr[i]);

        // Heapify the root of the reduced heap
        heapify(arr, i - 1, 1);
    }
}

// Driver code to test the heap sort function
int main() {
    // Adding a placeholder at index 0 for 1-based indexing
    vector<int> arr = {0, 12, 11, 13, 5, 6, 7};  // Initialize array with example values

    // Call heapSort to sort the array
    heapSort(arr);

    // Output the sorted array
    cout << "Sorted array is: ";
    for (int i = 1; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
