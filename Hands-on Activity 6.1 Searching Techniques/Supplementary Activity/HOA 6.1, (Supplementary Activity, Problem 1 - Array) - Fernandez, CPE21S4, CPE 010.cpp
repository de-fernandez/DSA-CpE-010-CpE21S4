#include <iostream>
using namespace std;

int searchArray(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 18;
    int comparisons = 0;

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            break;
        }
    }

    cout << "Number of comparisons in array approach: " << comparisons << std::endl;
    return 0;
}