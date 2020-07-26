/**
 * Creation         :       2018.11.18 16:30
 * Last Reversion   :       2018.11.18 16:37
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 99 multiplication table
 *      This function is to calculate 99 multiplication table.
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <cstdio>
using namespace std;

void MultiplicationTable() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << "*" << i << "=" << j*i << " ";
            if (j == 2 && (i == 3 || i == 4)) {
                cout << " ";
            }
        } 
        cout << "\n";
    }
}

int main() {
    MultiplicationTable();
    getchar();
    return 0;
}