#include <iostream>
using namespace std;


class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};


class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }


    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
        } else {
            insertRecursive(root, value);
        }
    }

   
    void insertRecursive(Node* node, int value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new Node(value);
            } else {
                insertRecursive(node->left, value);
            }
        } else if (value > node->value) {
            if (node->right == nullptr) {
                node->right = new Node(value);
            } else {
                insertRecursive(node->right, value);
            }
        }
    }

    
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

   
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

   
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }
    }

    void displayTraversals() {
        cout << "In-order Traversal: ";
        inorder(root);
        cout << "\nPre-order Traversal: ";
        preorder(root);
        cout << "\nPost-order Traversal: ";
        postorder(root);
        cout << endl;
    }
};


int main() {
    BinaryTree tree;

 
    int values[] = {50, 30, 70, 20, 40, 60, 80};

   
    for (int value : values) {
        tree.insert(value);
    }

   
    tree.displayTraversals();

    return 0;
}
