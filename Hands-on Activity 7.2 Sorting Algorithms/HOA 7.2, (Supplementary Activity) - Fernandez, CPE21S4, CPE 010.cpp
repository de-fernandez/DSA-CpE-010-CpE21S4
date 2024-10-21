#include <iostream>
using namespace std;

void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        int leftSize = pivotIndex - low;
        int rightSize = high - pivotIndex;
        int left[leftSize];
        int right[rightSize];

        for (int i = 0; i < leftSize; i++) {
            left[i] = arr[low + i];
        }
        for (int i = 0; i < rightSize; i++) {
            right[i] = arr[pivotIndex + 1 + i];
        }

        shellSort(left, leftSize);
        shellSort(right, rightSize);
        for (int i = 0; i < leftSize; i++) {
            arr[low + i] = left[i];
        }
        arr[pivotIndex] = arr[pivotIndex];
        for (int i = 0; i < rightSize; i++) {
            arr[pivotIndex + 1 + i] = right[i];
        }
    }
}

int main() {
    int array[] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Original Array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(array, 0, size - 1);

    cout << "Sorted Array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}