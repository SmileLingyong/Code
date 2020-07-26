/**
 * Creation         :       2018.11.18 17:03
 * Last Reversion   :       2018.11.18 17:08
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * Fibonacci
 *      Everyone knows the Fibonacci sequence. Now you need to enter an integer n.
 *      Please output the nth item of the Fibonacci sequence (starting at 0 and 0th item is 0).
 *      0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {smilelingyong@163.com}
 * */
#include <stdio.h>

int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0;
    int b = 1;
    int c = 1;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int FibonacciRecursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1) 
        return 1;
    return FibonacciRecursive(n-2) + FibonacciRecursive(n-1);
}

int main() {
    int n;
    printf("Please input a int number:");
    while (scanf("%d", &n) != EOF) {
        printf("Fibonacci(%d) is %d\n", n, Fibonacci(n));
        printf("FibonacciRecursive(%d) is %d\n", n, FibonacciRecursive(n));
        printf("Please input a int number:");
    }
    return 0;
}