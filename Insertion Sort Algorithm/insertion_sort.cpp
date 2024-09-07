#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    // Use vector for dynamic arrays
    vector<int> arr(n);

    cout << "Input your array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Index[" << i << "] : ";
        cin >> arr[i];
    }

    // Output array before insertion sort
    cout << "Output array before Insertion Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    // Output array after insertion sort
    cout << "Output array after Insertion Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
