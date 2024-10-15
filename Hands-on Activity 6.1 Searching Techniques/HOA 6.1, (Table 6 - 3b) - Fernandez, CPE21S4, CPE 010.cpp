#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
Node<T>* new_node(T data) {
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = nullptr;
    return node;
}

template <typename T>
Node<T>* linearSearch(Node<T>* head, T key) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

int main() {
    char choice = 'y';
    int count = 1;
    int newData;
    Node<int>* temp, *head, *node;

    while (choice == 'y') {
        cout << "Enter data: ";
        cin >> newData;

        if (count == 1) {
            head = new_node(newData);
            cout << "Successfully added " << head->data << " to the list.\n";
            count++;
        } else if (count == 2) {
            node = new_node(newData);
            head->next = node;
            node->next = NULL;
            cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        } else {
            temp = head;
            while (true) {
                if (temp->next == NULL)
                    break;
                temp = temp->next;
            }
            node = new_node(newData);
            temp->next = node;
            cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }

        cout << "Continue? (y/n)";
        cin >> choice;
        if (choice == 'n')
            break;
    }

    Node<int>* currNode;
    currNode = head;
    cout << "Linked list: ";
    while (currNode != NULL) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    Node<int>* result = linearSearch(head, key);

    if (result != nullptr) {
        cout << "Key found: " << result->data << endl;
    } else {
        cout << "Key not found." << endl;
    }

    currNode = head;
    while (currNode != NULL) {
        Node<int>* nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

    return 0;
}