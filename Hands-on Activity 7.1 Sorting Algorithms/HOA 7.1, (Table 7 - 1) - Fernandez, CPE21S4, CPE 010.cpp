#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int size = 100;

void generateRandomArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[size];
    generateRandomArray(arr, size);
    cout << "Original Array: ";
    printArray(arr, size);
    return 0;
}