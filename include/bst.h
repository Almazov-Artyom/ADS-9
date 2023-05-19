// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>

class BST {
private:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
    int h = 0;
    int h1 = 0;
    Node* root;
    Node* ADD(Node* root, T value) {
        if (!root) {
            root = new Node;
            root->value = value;
            root->count = 1;
            root->right = root->left = nullptr;
            return root;
        } else if (root->value > value) {
            h++;
            root->left = ADD(root->left, value);
        } else if (root->value < value) {
            h++;
            root->right = ADD(root->right, value);
        } else {
            root->count++;
        }
        if (h > h1) {
            h1 = h;
        }
        h = 0;
        return root;
    }
    int SEARCH(Node* &root, T value) {
        int j = 0;
        if (root->value == value) {
            j = root->count;
        }
        if (root->value > value) {
            j = SEARCH(root->left, value);
        }
        if (root->value < value) {
            j = SEARCH(root->right, value);
        }
        return j;
    }

public:
    BST(): root(nullptr) {}
    void add(T value) {
        root = ADD(root, value);
    }
    int search(T value) {
        return SEARCH(root, value);
    }
    int depth() {
        return h1;
    }
};
#endif  // INCLUDE_BST_H_
