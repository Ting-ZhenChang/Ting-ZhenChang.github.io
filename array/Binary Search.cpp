#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printheader(int size);
int binarysearch(int s[], int searchkey, int low, int high, int size);
void printrow(int s[], int low, int middle, int high, int size);

int main() {
    const int size = 15;
    int a[size];
    int searchkey;

    // 建立陣列 a[0..14] = 0, 2, 4, ..., 28
    for (int i = 0; i < size; i++) {
        a[i] = 2 * i;
    }

    cout << "打出0到28的數字: ";
    cin >> searchkey;

    printheader(size);

    int result = binarysearch(a, searchkey, 0, size - 1, size);

    if (result != -1) {
        cout << searchkey << "是在矩陣中的第 " << result << endl;
    } else {
        cout << searchkey << "沒找到" << endl;
    }

    return 0;
}

// 1. 印出標頭（欄位編號與底線）
void printheader(int size) {
    cout << "\n開頭\n";

    for (int i = 0; i < size; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int k = 0; k < size; k++) {
        cout << "-";
    }
    cout << endl;
}

// 2. Binary Search
int binarysearch(int s[], int searchkey, int low, int high, int size) {
    int middle;

    while (low <= high) {
        middle = (low + high) / 2;  // 計算中間值索引

        printrow(s, low, middle, high, size); // 顯示搜尋範圍與中間值

        if (searchkey == s[middle]) {       // 找到目標
            return middle;
        } else if (searchkey < s[middle]) { // 往左半邊搜尋
            high = middle - 1;
        } else {                             // 往右半邊搜尋
            low = middle + 1;
        }
    }

    return -1; // 沒找到
}

// 3. 印出目前搜尋的範圍與中間值
void printrow(int s[], int low, int middle, int high, int size) {
    for (int m = 0; m < size; m++) {
        if (m < low || m > high) {
            cout << "     "; // 區間外的留白
        } else if (m == middle) {
            cout << s[m] << "*"; // 中間值加星號
        } else {
            cout << s[m] << " "; // 區間內正常印
        }
    }
    cout << endl;
}
