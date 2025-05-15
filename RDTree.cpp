#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data): data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
private:
    Node* root;

    void rotateLeft(Node* &x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) y->left->parent = x;

        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* &x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) y->right->parent = x;

        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node* &k) {
        Node* parent = nullptr;
        Node* grandparent = nullptr;

        while (k != root && k->color == RED && k->parent->color == RED) {
            parent = k->parent;
            grandparent = parent->parent;

            // Parent is left child of grandparent
            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                // Case 1: Uncle is red
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    k = grandparent;
                } else {
                    // Case 2: Node is right child
                    if (k == parent->right) {
                        rotateLeft(parent);
                        k = parent;
                        parent = k->parent;
                    }

                    // Case 3: Node is left child
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    k = parent;
                }
            } else {
                // Mirror case: parent is right child of grandparent
                Node* uncle = grandparent->left;

                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    k = grandparent;
                } else {
                    if (k == parent->left) {
                        rotateRight(parent);
                        k = parent;
                        parent = k->parent;
                    }

                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    k = parent;
                }
            }
        }

        root->color = BLACK;
    }

    void inOrderHelper(Node* node) {
        if (node == nullptr) return;
        inOrderHelper(node->left);
        cout << node->data << (node->color == RED ? "R " : "B ");
        inOrderHelper(node->right);
    }

public:
    RBTree() : root(nullptr) {}

    void insert(const int &data) {
        Node* node = new Node(data);
        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr) {
            y = x;
            if (node->data < x->data) x = x->left;
            else x = x->right;
        }

        node->parent = y;
        if (y == nullptr) root = node;
        else if (node->data < y->data) y->left = node;
        else y->right = node;

        fixInsert(node);
    }

    void inOrder() {
        inOrderHelper(root);
        cout << endl;
    }
};

int main() {
    RBTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);

    cout << "In-order traversal (value followed by color R/B):\n";
    tree.inOrder();

    return 0;
}
