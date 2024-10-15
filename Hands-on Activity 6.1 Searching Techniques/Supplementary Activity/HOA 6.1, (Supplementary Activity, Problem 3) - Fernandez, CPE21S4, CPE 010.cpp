#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        cout << "Key " << key << " found at index " << result << endl;
    } else {
        cout << "Key " << key << " not found" << endl;
    }
    return 0;
}