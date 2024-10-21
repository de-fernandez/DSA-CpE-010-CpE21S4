#include <iostream>
#include <ctime>
using namespace std;

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

void quicksort(int A[], int low, int high) {
    if (low < high) {
        int pivot = partition(A, low, high);
        quicksort(A, low, pivot - 1);
        quicksort(A, pivot + 1, high);
    }
}

int main() {
    const int size = 100;
    int array[size];
    srand(static_cast<unsigned int>(time(0)));
    
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 1000 + 1;
    }
    cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << "\n\n";
    
    quicksort(array, 0, size - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
