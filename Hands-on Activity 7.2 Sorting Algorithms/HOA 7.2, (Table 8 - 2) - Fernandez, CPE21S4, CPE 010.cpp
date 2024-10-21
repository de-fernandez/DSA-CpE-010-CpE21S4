#include <iostream>
#include <ctime>
using namespace std;

void shellSort(int array[], int size) {
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

int main() {
    const int size = 100;
    int array[size];
    srand(static_cast<unsigned int>(time(0)));
    
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 1000 + 1;
    }
    cout << "Unsorted Array: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << "\n\n";

    shellSort(array, size);
    cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}