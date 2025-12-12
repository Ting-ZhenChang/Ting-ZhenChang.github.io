/****************************************************************
 * 功能：
 * 1. 建立 Binary Tree（可插入節點）
 * 2. 使用 ASCII 方式列印樹的結構
 *
 * 說明：
 * - Node 結構包含 value, left, right
 * - insert() 函式依照 BST 規則插入節點
 * - printTree() 函式用遞迴列印樹的右子樹在上，左子樹在下

執行結果:
Binary tree:
       64
           55
50
      25
           15

 *****************************************************************/

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}

    // 插入節點
    void insert(int newValue) {
        if (newValue < value) {
            if (left == nullptr) left = new Node(newValue);
            else left->insert(newValue);
        } else if (newValue > value) {
            if (right == nullptr) right = new Node(newValue);
            else right->insert(newValue);
        }
    }
};

void printTree(Node* root, int space = 0, int indent = 6) {
    if (root == nullptr) return;

    space += indent;

    printTree(root->right, space);
    cout << endl;

    for (int i = indent; i < space; i++)
        cout << " ";
    cout << root->value << "\n";

    printTree(root->left, space);
}

int main() {
    Node* tree = new Node(50);
    tree->insert(25);
    tree->insert(15);
    tree->insert(64);
    tree->insert(55);

    // 印出樹
    cout << "Binary Tree:" << endl;
    printTree(tree);

    return 0;
}
