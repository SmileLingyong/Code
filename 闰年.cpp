/**
 * Creation         :       2018.11.18 17:10
 * Last Reversion   :       2018.11.18 17:12
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Leap Year
 * Judging the leap year:
 *      The leap year can satisfy one of the following conditions 1 and 2
 *      1. can be divisible by 4, but cannot be divisible by 100
 *      2. can be divisible by 400
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
using namespace std;

int LeapYear(int n) {
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) 
        return 1;
    else
        return 0;
}

int main() {
    int year;
    cout << "Please input a year number:";
    while(cin >> year){
        if(LeapYear(year))
            cout << year << " is a leap year!" << endl;
        else
            cout << year << " is not a leap year!" << endl;
        cout << "Please input a year number:";
    }
    // system("pause");
    return 0;
}