#include <iostream>
using namespace std;

class Node {
public:
    string songName;
    Node *next;
};

void listTraversal(Node* head) {
    if (head == nullptr) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp -> songName << " -> ";
        temp = temp -> next;
    } while (temp != head);
    cout << "(back to start)" << endl;
}

void inAtHead(Node* &head, string newSong) {
    Node* newNode = new Node();
    newNode -> songName = newSong;
    if (head == nullptr) {
        newNode -> next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp -> next != head) {
            temp = temp -> next;
        }
        newNode -> next = head;
        temp -> next = newNode;
        head = newNode;
    }
}

void inAtEnd(Node* &head, string newSong) {
    Node* newNode = new Node();
    newNode -> songName = newSong;
    if (head == nullptr) {
        newNode -> next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp -> next != head) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> next = head;
    }
}

void delNode(Node*& head, string songName) {
    if (head == nullptr) return;
    
    Node *temp = head, *prev = nullptr;

    if (temp != nullptr && temp -> songName == songName) {
        if (temp -> next == head) {
            delete temp;
            head = nullptr;
            return;
        }

        while (temp -> next != head) {
            temp = temp-> next;
        }
        temp -> next = head -> next;
        delete head;
        head = temp -> next;
        return;
    }

    do {
        prev = temp;
        temp = temp -> next;
    } while (temp != head && temp -> songName != songName);
    
    if (temp == head) return;

    prev -> next = temp -> next;
    delete temp;
}

int main() {
    Node *head = nullptr;
    inAtEnd(head, "Song A");
    inAtEnd(head, "Song B");
    inAtEnd(head, "Song C");
    inAtEnd(head, "Song D");
    cout << "Initial Playlist: " << endl;
    listTraversal(head);

    inAtHead(head, "Song X");
    cout << "\nAfter adding 'Song X' at the head: " << endl;
    listTraversal(head);

    delNode(head, "Song B");
    cout << "\nAfter deleting 'Song B': " << endl;
    listTraversal(head);

    inAtEnd(head, "Song Y");
    cout << "\nAfter adding 'Song Y' at the end: " << endl;
    listTraversal(head);

    return 0;
}
