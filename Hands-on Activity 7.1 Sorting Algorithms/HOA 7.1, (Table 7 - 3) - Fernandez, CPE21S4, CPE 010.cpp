#include <iostream>
using namespace std;

void printArray(int arr[], size_t arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize) {
    int position, j;
    T smallestElem = A[K];
    position = K;
    for (int J = K + 1; J < arrSize; J++) {
        if (A[J] < smallestElem) {
            smallestElem = A[J];
            position = J;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], const int N) {
    int POS, temp, pass = 0;
    for (int i = 0; i < N; i++) {
        POS = Routine_Smallest(arr, i, N);
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
        pass++;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, arrSize);
    selectionSort(arr, arrSize);
    cout << "Sorted array: ";
    printArray(arr, arrSize);
    return 0;
}