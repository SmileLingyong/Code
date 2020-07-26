/**
 * Creation         :       2018.11.18 17:03
 * Last Reversion   :       2018.11.18 17:08
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Fibonacci
 *      Everyone knows the Fibonacci sequence. Now you need to enter an integer n.
 *      Please output the nth item of the Fibonacci sequence (starting at 0 and 0th item is 0).
 *      0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
using namespace std;

/**
 * 递归方式
 */ 
int FibonacciRecursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return FibonacciRecursive(n - 2) + FibonacciRecursive(n - 1);
}

/**
 * 非递归：动态规划
 */ 
int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    cout << "Please input a int number:";
    while (cin >> n) {
        // Test Fibonacci function
        cout << "Fibonacci(" << n << ") is : " << Fibonacci(n) << endl;

        // Test Fibonacci Recursive function
        cout << "FibonacciRecursive(" << n << ") is : " << FibonacciRecursive(n) << endl;
        cout << "Please input a int number:";
    }
    // system("pause");
    return 0;
}