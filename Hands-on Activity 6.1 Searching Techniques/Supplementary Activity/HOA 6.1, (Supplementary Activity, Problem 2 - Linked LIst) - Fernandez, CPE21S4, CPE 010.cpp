#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int repeatLinkedList(Node* head, int key) {
    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = createNode(15);
    head->next = createNode(18);
    head->next->next = createNode(2);
    head->next->next->next = createNode(19);
    head->next->next->next->next = createNode(18);
    head->next->next->next->next->next = createNode(0);
    head->next->next->next->next->next->next = createNode(8);
    head->next->next->next->next->next->next->next = createNode(14);
    head->next->next->next->next->next->next->next->next = createNode(19);
    head->next->next->next->next->next->next->next->next->next = createNode(14);

    int key = 18;
    int count = repeatLinkedList(head, key);

    cout << "Number of repeating value of " << key << " in linked list approach: " << count << endl;
    return 0;
}