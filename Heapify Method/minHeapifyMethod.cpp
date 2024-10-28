#include <iostream>
#include <vector>
using namespace std;

// Function to min-heapify a subtree rooted with node i
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;          // Assume the root is the smallest
    int left = 2 * i;          // Left child index (1-based)
    int right = 2 * i + 1;     // Right child index (1-based)

    // If left child exists and is smaller than root
    if (left <= n && arr[left] < arr[smallest])
        smallest = left;

    // If right child exists and is smaller than the smallest so far
    if (right <= n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not the root, we need to swap and continue heapifying
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest); // Recursively heapify the affected subtree
    }
}

// Function to perform heap sort in descending order using min-heap
void heapSortDescending(vector<int>& arr) {
    int n = arr.size() - 1;  // Adjust size for 1-based indexing

    // Step 1: Build a min-heap from the input array
    for (int i = n / 2; i >= 1; i--)
        minHeapify(arr, n, i);

    // Step 2: Extract elements from the min-heap to get descending order
    for (int i = n; i > 1; i--) {
        // Move the current root (smallest element) to the end of the array
        swap(arr[1], arr[i]);

        // Heapify the root of the reduced heap
        minHeapify(arr, i - 1, 1);
    }
}

// Driver code to test the heap sort function in descending order
int main() {
    // Adding a placeholder at index 0 for 1-based indexing
    vector<int> arr = {0, 12, 11, 13, 5, 6, 7};  // Initialize array with example values

    // Call heapSortDescending to sort the array
    heapSortDescending(arr);

    // Output the sorted array
    cout << "Sorted array in descending order is: ";
    for (int i = 1; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
