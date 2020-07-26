/**
 * Creation         :       2018.11.18 16:38
 * Last Reversion   :       2018.11.18 16:40
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * PrimeNumber
 *      Determine if a number is a prime.
 *      If it is a composite number, its minimum prime factor must be less than
 * or equal to his square root.
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {smilelingyong@163.com}
 */

#include <cmath>
#include <iostream>
using namespace std;

int PrimeNumber(int n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int n;
    cout << "Please input a int number:";
    while (cin >> n) {
        if (PrimeNumber(n)) {
            cout << n << " is a prime number!" << endl;
        } else {
            cout << n << " is not a prime number!" << endl;
        }

        cout << "Please input a int number:";
    }
    // system("pause");
    return 0;
}