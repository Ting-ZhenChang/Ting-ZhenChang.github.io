//排序前的陣列: 5 1 4 3 8

//第 1 輪排序: 1 4 3 5 8
//第 2 輪排序: 1 3 4 5 8
//第 3 輪排序: 1 3 4 5 8
//第 4 輪排序: 1 3 4 5 8

//排序後的陣列: 1 3 4 5 8

#include <iostream>
using namespace std;

// 冒泡排序函式
void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << "第 " << i + 1 << " 輪排序: ";
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                // 交換 A[j] 和 A[j+1]
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
        // 印出每輪排序結果
        for (int k = 0; k < n; k++) {
            cout << A[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[] = { 5, 1, 4, 3, 8 };
    int n = sizeof(A) / sizeof(A[0]);

    cout << "排序前的陣列: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;

    bubbleSort(A, n);

    cout << endl << "排序後的陣列: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
