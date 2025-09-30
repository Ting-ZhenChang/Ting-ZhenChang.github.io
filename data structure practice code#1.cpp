#include <iostream>
using namespace std;

void arraysort(int a[], int n) {
	for (int i = 0;i<n-1;i++) {
		int min_index = i;
		for (int j = i + 1;j < n;j++) {
			if (a[j] < a[min_index]){	//如果後面值小於前面的數，就找到最小值了，min_index = j ;
				min_index = j;
			}
		}
		if (a[min_index] != i) {		//這時候min_index不可能等於i，swap最小值跟a[i]
				int temp = a[i];
				a[i] = a[min_index];
				a[min_index] = temp;
		}

		cout << "step" << i + 1 << ":";
		for (int k = 0;k < n ;k++) {
			cout << a[k] << " ";
		}
		cout << endl;
	}	
}


int main() {
	int A[] = { 4, 90, 95, 87, 71, 19, 5, 70 };
	int n = sizeof(A) / sizeof(A[0]);

	cout << "Original array: ";
	for (int i = 0; i < n; i++) 
	cout << A[i] << " ";
	cout << endl;

	arraysort(A, n);

	cout << "Sorted array: ";
	for (int i = 0; i < n; i++) 
	cout << A[i] << " ";
	cout << endl;

	return 0;
}