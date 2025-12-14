#include<iostream>
#include<iomanip>

using std::cin;
using std::cout;
using std::endl;

void findmax(int[], int);


int main() {


	int data[5] = { 12,35,7,64,22 };

	
	findmax(data, 5);	//電腦進入 findmax函式中

	return 0;


}

void findmax(int s[], int size) {	//電腦跳過來，s[] → 指向 data[] 的記憶體位置（同一份陣列），size → 是 5

	int maxvalue=s[0];

	for (int i = 1;i < size-1;i++) {

		if (s[i] > maxvalue) {

			maxvalue = s[i];

		}

	}
	cout << "陣列中的最大值是:" << maxvalue << endl;
	
}
