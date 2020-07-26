/**
 * Creation         :       2018.11.18 19:14
 * Last Reversion   :       2018.11.18 19:18
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Daffodil Number.
 *      Print out all the "daffodil number", the so-called "daffodil number" refers to a three-digit number,
 *      the number of each cube is equal to the number itself.
 * For example:
 *      153 is a "affodil number" because the cube of 153 = 1^3 + 5^3 + 3^3.
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <cstdio>
using namespace std;

void DaffodilNumber() {
    int a, b, c, i;
    for (i = 100; i < 999; ++i) {
        a = i / 100;
        b = (i - a * 100) / 10;
        c = i % 10;
        if (a * a * a + b * b * b + c * c * c == i) {
            cout << i << " ";
        }
    }
}

int main() {
    DaffodilNumber();
    getchar();
    return 0;
}
