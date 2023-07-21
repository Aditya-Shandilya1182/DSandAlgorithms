#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        // Assume the current element is the minimum
        int minIndex = i;

        // Find the index of the minimum element in the remaining unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first unsorted element
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    selectionSort(arr);

    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
