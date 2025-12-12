#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}

    void insert(int newValue) {
        if (newValue < value) {
            if (left == nullptr) left = new Node(newValue);
            else left->insert(newValue);
        }
        else if (newValue > value) {
            if (right == nullptr) right = new Node(newValue);
            else right->insert(newValue);
        }
    }

    int getDepth(Node* tree) {
        if (tree == nullptr) return 0;
        int leftDepth = getDepth(tree->left);
        int rightDepth = getDepth(tree->right);
        return 1 + max(leftDepth, rightDepth);
    }

    bool checkBalance(Node* tree) {
        if (tree == nullptr) return true;

        int ldepth = getDepth(tree->left);
        int rdepth = getDepth(tree->right);
        int diff = abs(ldepth - rdepth);

        return (diff <= 1 &&
            checkBalance(tree->left) &&
            checkBalance(tree->right));
    }
};

int main() {
    Node* tree = new Node(50);
    tree->insert(25);
    tree->insert(15);
    tree->insert(64);
    tree->insert(55);
    tree->insert(40);
    tree->insert(70);

    bool isBalanced = tree->checkBalance(tree);
    cout << (isBalanced ? "Tree is balanced" : "Tree is not balanced") << endl;
}
