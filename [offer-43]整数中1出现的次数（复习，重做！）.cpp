/**
 * Creation         :       2019.04.21 23:12
 * Last Reversion   :       2019.04.21 23:25
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * NumberOf1Between1AndNSolution(整数中1出现的次数)
 * 题目描述
 *    求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他
 * 特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面
 * 问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负
 * 整数区间中1出现的次数（从1 到 n 中1出现的次数）。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;


/**
 * 判断整数每一位是否为1
 */ 
int NumberOf1(int x) {
    int one_num = 0;
    while (x) {
        if (x % 10 == 1) {
            one_num++;
        }
        x /= 10;
    }
    return one_num;
}

/**
 * 方法一：
 *    累加1～n中每个整数1出现的次数。
 * 时间复杂度 O(nlogn)
 */ 
int NumberOf1Between1AndN_Solution(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += NumberOf1(i);
    }
    return sum;
}

/**
 * 方法二：(还没有细看)
 *    
 */ 

int main() {
    int n;
    cin >> n;
    cout << NumberOf1Between1AndN_Solution(n) << endl;
    return 0;
}