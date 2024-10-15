#include <iostream>
using namespace std;

int repeatArray(int arr[], int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 18;

    int count = repeatArray(arr, n, key);

    cout << "Number of repeating value of " << key << " in array approach: " << count << endl;
    return 0;
}