#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    insertionSort(arr);

    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
