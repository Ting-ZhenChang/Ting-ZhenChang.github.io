  #include <iostream>
	
	using std::cout;
	using std::cin;
	using std::endl;

	int linersearch(int[],int, int);		//linersearch有三個參數

	int main() {

		const int size = 100;
		int a[size];			// 1. 宣告陣列 a[0] ~ a[99]
		int searchkey;

		for (int i = 0;i < size;i++) {

			a[i] = 2 * i;					// 2.a[0] = 0，a[1] = 2，a[2] = 4，a[3] = 6...a[99] = 198


		}

		cout << "輸入要找的值:";
		cin >> searchkey;

		int element = linersearch(a, searchkey,size);		// 3.我把陣列 a、要找的值 searchKey，和陣列大小 100 傳給 linearSearch() 函式


		if (element != -1) {							// 7.如果 element 有值（不是 -1），印出「找到了在哪一格」， 如果 element == -1，就印「找不到」
						
			cout << "找到值了:" << element << endl;

		}

		else

			cout << "沒找到值:" << endl;

		return 0;



	}



	int linersearch(int s[], int key, int size) {	// 4.我要幫你在陣列中一個一個比，看看 key 有沒有出現

		for (int j = 0;j < size;j++) {

			if (s[j] == key) {

				return j;		// 5.找到了，就馬上回傳這個位置

			}

		}

		return -1;		// 6.陣列位置一定是從 0 開始：a[0], a[1], ..., a[99]，所以「-1」這個數字是不可能存在的有效位置，我們就用它來當作「沒找到」的訊號（signal）
	}
