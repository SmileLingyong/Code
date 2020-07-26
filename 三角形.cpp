/**
 * Creation         :       2018.12.07 00:06
 * Last Reversion   :       2018.12.07 00:06
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Judging triangle
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {@smilelingyong@163.com}
 */

#include <iostream>
using namespace std;

void Triangle(int a, int b, int c) {
    int flag = 0;
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            cout << "等边";
            flag = 1;
        } else if (a == b || b == c || c == a) {
            cout << "等腰";
            flag = 1;
        }
        
        if (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a) {
            cout << "直角";
            flag = 1;
        }
        if (!flag) {
            cout << "一般";
        }
        cout << "三角形\n";
    } else {
        cout << "不是三角形\n";
    }
}

int main() {
    int a, b, c;
    cout << "Please input the three sides of the triangle, separated by spaces: ";
    while (cin >> a >> b >> c) {
        Triangle(a, b, c);
    }
    // system("pause");
    return 0;
}