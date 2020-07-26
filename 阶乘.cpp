/**
 * Creation         :       2018.12.07 00:06
 * Last Reversion   :       2018.12.07 00:06
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Factorial
 *      输入一个正整数N，输出N的阶乘。
 * 输入描述:
 *      正整数N(0<=N<=100)
 * 输出描述:
 *      输入可能包括多组数据，对于每一组输入数据，输出N的阶乘
 * 示例1
 * 输入
 *      4
 *      5
 *      15
 * 输出
 *      24
 *      120
 *      1307674368000
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
using namespace std;

/**
 * @Factorial
 *      This function is Basic factorial method, but not suitable for this problem.
 * */
int Factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * Factorial(n - 1);
}

/**
 * @BigNumFactorial
 *      Multiplication algorithm.
 * */
int BigNumFactorial(int n) {
    
}

int multiply(int m[101], int n[201], int product[301]) { //两因子m 、n，乘积product

    int sum1[102], sum2[102], i, j, k, s;  // sum2 、sum1中间过渡量
    for (i = 1; i <= 101; i++) {
        sum2[i] = 0;            // sum2所有位置零
    }                          
    for (j = 1; j < 201; j++) { // 在n的每一位上处理m
        for (i = 1; i <= 101; i++) 
            sum1[i] = 0;        // sum1所有位置零
        for (i = 1; i <= n[j]; i++) {   //通过每一层循环，实现乘法的加法化
            for (s = 1; s < 101; s++) 
                sum2[s] = m[s] + sum1[s];
            for (k = 1; k <= 101; k++) 
                sum1[k] = sum2[k];
        }
        for (k = j; k <= 100 + j; k++)
            product[k] = sum2[k - j + 1] + product[k];  // 即是实现了乘法过程中的加法
    }
    for (i = 1; i < 301; i++) { // 进位处理
        j = product[i] / 10;
        product[i + 1] += j;
        product[i] -= j * 10;
    }
    return 0;
}

int main() {
    // int n;
    // cout << "Please input a int number: ";
    // while (cin >> n) {
    //     cout << n << "! is : " << BigNumFactorial(n) << endl;
    //     cout << "Please input a int number: ";
    // }

    int a, b;
    cout << "Please input two int num:";
    while(cin >> a >> b){
        cout << multiply(a, b) << endl;
        cout << "Please input two int num:";
    }
    
    // system("pause");
    return 0;
}