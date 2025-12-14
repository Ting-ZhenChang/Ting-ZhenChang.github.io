//InsertData(a): 從 root 開始，一路往左 / 右比大小，找到 null 的位置，插入成為葉節點
//SearchDataSearchDa)，從 root 開始遞迴，比大小，決定往左或右，找到或回傳 null
//found:55

#include <iostream>
using namespace std;


struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};


void InsertData(Node*& root, int a) {
    Node* b = root;   
    Node* c = nullptr; 

    // 若根節點為空，直接成為 root
    if (b == nullptr) {
        root = new Node(a);
        return;
    }

    // 尋找插入位置
    while (b != nullptr) {
        c = b;
        if (a > b->value) {
            b = b->right;
        }
        else {
            b = b->left;
        }
    }

    // 插入新節點
    if (a > c->value) {
        c->right = new Node(a);
    }
    else {
        c->left = new Node(a);
    }
}

// 搜尋資料（對應 SearchData）
Node* SearchData(Node* root, int a) {
    if (root == nullptr || root->value == a) {
        return root;
    }

    if (a > root->value) {
        return SearchData(root->right, a);
    }
    else {
        return SearchData(root->left, a);
    }
}

// 主程式測試
int main() {
    Node* root = nullptr;

    // 插入資料
    InsertData(root, 50);
    InsertData(root, 25);
    InsertData(root, 15);
    InsertData(root, 64);
    InsertData(root, 55);
    InsertData(root, 70);

    // 搜尋測試
    int key = 55;
    Node* result = SearchData(root, key);

    if (result != nullptr) {
        cout << "Found: " << result->value << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

    return 0;
}


