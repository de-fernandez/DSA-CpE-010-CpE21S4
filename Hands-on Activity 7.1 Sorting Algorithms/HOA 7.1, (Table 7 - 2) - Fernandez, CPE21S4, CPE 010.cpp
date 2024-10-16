#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], size_t arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        bool swapped = false;
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, arrSize);
    bubbleSort(arr, arrSize);
    cout << "Sorted array: ";
    printArray(arr, arrSize);
    return 0;
}