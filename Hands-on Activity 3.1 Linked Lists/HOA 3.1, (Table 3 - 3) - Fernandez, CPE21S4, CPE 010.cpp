#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *next;
};

void listTraversal(Node* n) {
    while (n != nullptr) {
        cout << n -> data << " ";
        n = n -> next;
    }
    cout << endl;
}

void inAtHead(Node* & head, char newData) {
    Node* newNode = new Node();
    newNode -> data = newData;
    newNode -> next = head;
    head = newNode;
}

void inAtAny(Node* prevNode, char newData) {
    if (prevNode == nullptr) {
        cout << "Previous node cannot be null." << endl;
        return;
    }
    Node* newNode = new Node();
    newNode -> data = newData;
    newNode -> next = prevNode -> next;
    prevNode -> next = newNode;
}

void inAtEnd(Node* & head, char newData) {
    Node* newNode = new Node();
    newNode -> data = newData;
    newNode -> next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* last = head;
    while (last -> next != nullptr) {
        last = last -> next;
    }
    last -> next = newNode;
}

void delNode(Node*& head, char key) {
    Node* temp = head;
    Node* prev = nullptr;
    if (temp != nullptr && temp -> data == key) {
        head = temp -> next;
        delete temp;
        return;
    }
    while (temp != nullptr && temp -> data != key) {
        prev = temp;
        temp = temp -> next;
    }
    if (temp == nullptr) return;
    prev -> next = temp -> next;
    delete temp;
}

int main() {
    // Step 1
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;
    Node *last = NULL;
    // Step 2
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;
    last = new Node;
    // Step 3
    head->data = 'C';
    head->next = second;
    second->data = 'P';
    second->next = third;
    third->data = 'E';
    third->next = fourth;
    fourth->data = '1';
    fourth->next = fifth;
    fifth->data = '0';
    fifth->next = last;
    // Step 4
    last->data = '1';
    last->next = nullptr;

    listTraversal(head);
    cout << endl << "Final Output: " << endl;
    inAtAny(head -> next, 'E');
    inAtHead(head, 'G');
    delNode(head, 'C');
    delNode(head, 'P');

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}