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

int sequentialSearchLinkedList(Node* head, int key) {
    Node* temp = head;
    int comparisons = 0;

    while (temp != nullptr) {
        comparisons++;
        if (temp->data == key) {
            return comparisons;
        }
        temp = temp->next;
    }
    return -1;
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
    int comparisons = sequentialSearchLinkedList(head, key);

    cout << "Number of comparisons in linked list approach: " << comparisons << endl;
    return 0;
}