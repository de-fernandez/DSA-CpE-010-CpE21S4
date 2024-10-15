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
  node->next = NULL;
  return node;
}

int linearLS(Node<char>* head, char dataFind) {
  int index = 0;
  Node<char>* current = head;
  while (current != NULL) {
    if (current->data == dataFind) {
      cout << "Found '" << dataFind << "' at index " << index << endl;
      return index;
    }
    index++;
    current = current->next;
  }
  cout << "Character not found in the list." << endl;
  return -1;
}

int main() {
  Node<char>* name1 = new_node('R');
  Node<char>* name2 = new_node('o');
  Node<char>* name3 = new_node('m');
  Node<char>* name4 = new_node('a');
  Node<char>* name5 = new_node('n');

  name1->next = name2;
  name2->next = name3;
  name3->next = name4;
  name4->next = name5;
  name5->next = NULL;

  linearLS(name1, 'n');

  return 0;
}