#include <iostream>
#include <vector>

// Function to merge two subarrays
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Function to perform merge sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> arr;
    int n, element;

    // Input the size of the array
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Input the elements of the array
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> element;
        arr.push_back(element);
    }

    // Perform merge sort
    mergeSort(arr, 0, n - 1);

    // Output the sorted array
    std::cout << "Sorted array: ";
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}