#include <iostream>
#include <vector>

// Partition the array and return the index of the pivot element
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]); // Place the pivot element in its correct position
    return i + 1;
}

// Quicksort recursive function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Partition the array
        quickSort(arr, low, pivotIndex - 1); // Sort elements before the pivot
        quickSort(arr, pivotIndex + 1, high); // Sort elements after the pivot
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
