#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::left;
using std::setw;
using std::setprecision;

void printarray(int[][4],int,int);  //(矩陣,學生,考試)
int minimum(int[][4], int, int);
int maximum(int[][4], int, int);
double average(int[], int);         //(三位平均成績,考試)

int main() {

    int const student = 3;
    int const test = 4;

    int studentGrades[student][test] = {      //三位學生，四次成績
        {77, 68, 86, 73},
        {96, 87, 89, 78},
        {70, 90, 86, 81}
    };

    cout << "矩陣如下:" << endl;

    printarray(studentGrades, student, test);       // 1.呼叫printarray


    cout << "最低分為:" << minimum(studentGrades, student, test)                // 6.呼叫miniumu跟maxiumu
    << "\n最高分為:" << maximum(studentGrades, student, test) << endl;


    cout << fixed << setprecision(2);        // 設定小數點格式



    for (int w = 0;w < student;w++) {               // 9.呼叫average

        cout << "第" << w << "位學生平均成績:" << average(studentGrades[w], test)<<endl;

    }

    return 0;

}


void printarray(int s[][4],int student,int test) {           // 2.傳進來

    cout << left << "                 [0]  [1]  [2]  [3]" ;

    for (int i = 0;i < student;i++) {                         // 3.外層跑一圈，列印第一位學生
        
        cout << "\nstudentGrades[" << i << "] ";

        for (int j = 0;j<test;j++) {                       // 4.內層跑到底，列印四個成績

            cout << setw(5)<< s[i][j] << " ";

        }

        cout << endl;                                   // 5.內層跑完換行

    }

}


// 7.找出最低分
int minimum(int g[][4],int student,int test) {

    int lowgrade = 100;     // 先設定為一個不會比成績還低的數字（例如100）

    for (int i = 0;i < student;i++) {       //外層跑一圈，列印第一位學生
        for (int k = 0;k < test;k++) {      //內層跑到底，列印四個成績

            if (g[i][k] < lowgrade) {           //如果第一位學生的四個成績比lowgrade還低，那就更新lowgrade成績

                lowgrade = g[i][k];

            }

        }

    }

    return lowgrade;

}


// 8.找出最高分
int maximum(int g[][4],int student,int test) {

    int highgrade = 0;


    for (int r = 0;r < student;r++ ) {

        for (int p = 0;p < test; p++) {

            if (g[r][p] > highgrade)

                highgrade = g[r][p];

        }
    }

    return highgrade;

}


// 10.算平均
double average(int y[], int test) { 

    int total = 0;

    for (int q = 0;q < test;q++) {

        total += y[q];

    }

    return static_cast<double>(total) / test;

}


