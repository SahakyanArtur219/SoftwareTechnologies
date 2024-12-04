#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
private:
    Node<T>* root;

    Node<T>* insertRecursive(Node<T>* current, T value) {
        if (current == nullptr) return new Node<T>(value);

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        }
        else {
            current->right = insertRecursive(current->right, value);
        }
        return current;
    }

    Node<T>* deleteRecursive(Node<T>* current, T value) {
        if (current == nullptr) return nullptr;

        if (value < current->data) {
            current->left = deleteRecursive(current->left, value);
        }
        else if (value > current->data) {
            current->right = deleteRecursive(current->right, value);
        }
        else {
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                return nullptr;
            }
            if (current->left == nullptr) {
                Node<T>* temp = current->right;
                delete current;
                return temp;
            }
            if (current->right == nullptr) {
                Node<T>* temp = current->left;
                delete current;
                return temp;
            }

            Node<T>* successor = findMin(current->right);
            current->data = successor->data;
            current->right = deleteRecursive(current->right, successor->data);
        }
        return current;
    }

    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    bool searchRecursive(Node<T>* current, T value) {
        if (current == nullptr) return false;
        if (current->data == value) return true;
        return value < current->data
            ? searchRecursive(current->left, value)
            : searchRecursive(current->right, value);
    }

    void inorderRecursive(Node<T>* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

    void preorderRecursive(Node<T>* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }

    void postorderRecursive(Node<T>* node) {
        if (node != nullptr) {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insertNode(T value) {
        root = insertRecursive(root, value);
    }

    void deleteNode(T value) {
        root = deleteRecursive(root, value);
    }

    bool search(T value) {
        return searchRecursive(root, value);
    }

    void inorder() {
        inorderRecursive(root);
        cout << endl;
    }

    void preorder() {
        preorderRecursive(root);
        cout << endl;
    }

    void postorder() {
        postorderRecursive(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree<int> bst;

    bst.insertNode(50);
    bst.insertNode(30);
    bst.insertNode(70);
    bst.insertNode(20);
    bst.insertNode(40);
    bst.insertNode(60);
    bst.insertNode(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Preorder traversal: ";
    bst.preorder();

    cout << "Postorder traversal: ";
    bst.postorder();

    cout << "Searching for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Searching for 90: " << (bst.search(90) ? "Found" : "Not Found") << endl;

    bst.deleteNode(30);
    cout << "Inorder traversal after removing 30: ";
    bst.inorder();

    return 0;
}
