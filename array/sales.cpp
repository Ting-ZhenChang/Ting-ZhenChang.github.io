#include<iostream>
#include<iomanip>

using std::cin;
using std::cout;
using std::endl;

void mean(int[], int);
void medium(int[], int);
void mode(int[], int);
void bubble(int[], int);


int main() {

    int temps[3][7] = {

    {25, 26, 25, 24, 25, 27, 28}, // 城市 A
    {30, 29, 30, 31, 29, 30, 30}, // 城市 B
    {20, 21, 20, 22, 23, 20, 20}  // 城市 C

    };

    for (int i = 0;i < 3;i++) {

        cout << "---城市"<< char('A' + i) << " ---" << endl;
        mean(temps[i], 7);
        medium(temps[i], 7);
        mode(temps[i], 7);

    }

    return 0;

}


void mean(int s[], int size) {

    int total = 0;

    for (int i = 0; i < size;i++) {

        total += s[i];

    }
    cout << "平均氣溫=" << static_cast<double>(total) / size << endl;   

}

void medium(int s[],int size) {

    for (int k = 0;k < size;k++)

        bubble(s, size);

    cout << "中位數=" << s[size / 2] << endl;


}

void mode(int s[],int size) {

    int freq[101] = { 0 };  //建一個長度為 101 的陣列（從 0 到 100），每一格先放 0，用來統計「每個溫度出現幾次」

    int largest = 0;    //最多次
    int modevalue = 0;  

    for (int p = 0;p < size;p++) {

        ++freq[ s[p] ];   //我在第p天看到的溫度是 s[p]，我就在 freq[s[i]] 裡面加一

        if (freq[s[p]] > largest) {

            largest = freq[s[p]];   

            modevalue = s[p];

        }

    }

    cout << "眾數=" << modevalue << "(出現" << largest << "次)" << endl;
}

void bubble(int s[], int size) {

    for (int pass=0 ;pass<size - 1;pass++) {    

        for (int j = 0;j < size - 1;j++) {

            int hold = s[j];
            s[j] = s[j + 1];
            s[j + 1] = hold;

        }

    }



}