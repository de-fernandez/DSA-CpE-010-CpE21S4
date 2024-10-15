#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
};

template <typename T>
Node<T>* new_node(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
int linearSearch(T arr[], int n, T item) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int item = 8;

    int result = linearSearch(arr, n, item);

    if (result != -1) {
        cout << "Item " << item << " found at index " << result << endl;
    } else {
        cout << "Item " << item << " not found" << endl;
    }
    return 0;
}