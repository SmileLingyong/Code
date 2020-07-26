/**
 * Creation         :       2018.11.18 19:29
 * Last Reversion   :       2018.11.18 19:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Maximum common divisor and Minimum common multiple
 *      两个整数公有的倍数成为他们的公倍数，其中一个最小的公倍数是他们的最小公倍数
 *  求最小公倍数:
 *      最小公倍数 = 两整数的乘积 ÷ 最大公约数
 *  求最大公约数：
 *  （一）辗转相除法
 *      有两整数 a 和 b：
 *          ① a % b 得余数 c
 *          ② 若 c = 0，则 b 即为两数的最大公约数
 *          ③ 若 c ≠0，则 a=b， b=c，再回去执行 ①
 *      例如求 27 和 15 的最大公约数过程为：
 *          27÷15 余 12 ， 15÷12 余 3 ， 12÷3 余 0 因此， 3 即为最大公约数（自己动手画一下就明白了）
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {smilelingyong@163.com}
 */   

#include <iostream>
using namespace std;

void MaxComDivisorMinComMultiple(int a, int b) {
    int A, B, c;
    A = a, B = b;
    while((c = a % b) != 0) {
        a = b;
        b = c;
    }
    cout << "Maximum common divisor is :" << b << endl;
    cout << "Minimum common multiple is :" << A * B / b << endl;
}

int main() {
    int a, b;
    cout << "Please input two int number:";
    while(cin >> a >> b){
        MaxComDivisorMinComMultiple(a, b);
        cout << "Please input two int number:";
    }
    // system("pause");
    return 0;
}