/**
 * Creation         :       2019.04.21 23:49
 * Last Reversion   :       2019.04.21 23:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * GetDigitAtIndex(数字序列中的某一位数字)
 * 题目描述
 *    数字以 0123456789101112131415... 的格式序列化到一个字符串中，
 * 求这个字符串的第 index 位。在这个序列中，第5位（从0开始计数）是5，第13位是1，
 * 第19位是4，等等。请写一个函数，求任意第n为对应的数字。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <math.h>
using namespace std;

/**
 * m 位的数字总共有多少个
 * 1 => 10
 * 2 => 90
 * 3 => 900
 */ 
int CountOfIntegers(int digits) {
    if (digits == 1)
        return 10;
    int count = (int) pow(10, digits - 1);
    return 9 * count;
}

/**
 * 计算m位数字的第一个数字
 * 1 => 0
 * 2 => 10
 * 3 => 100
 */ 
int BeginNumber(int digits) {
    if (digits == 1)
        return 0;
    return (int) pow(10, digits-1);
}

/**
 * 找到的那一位数字位于某m位数之中后，再找出那一位数字
 * （这里用例子中的811位于3位数之中，然后找出位于哪个三位数字，并且位于这个三位数字中的第几位）
 */ 
int DigitAtIndex(int index, int digits) {
    int number = BeginNumber(digits) + index / digits;  // 找到该index 811这个数字位于3位数字中的哪个数字，(三位数起始位置)100 + 811/3 = 370，即位于370这个数字之中
    int index_from_right = digits - index % digits;     // 并且 811 = 270x3 + 1，所以是370这个数字中的第1位（最左边的为第0位），即可通过不断除以10，得到每一位，
                                                        // 输出位于第 digits - 1 = 3 - 1 = 2(从右往左的第2位，最右边为第1位)
    for (int i = 1; i < index_from_right; i++)
        number /= 10;
    return number % 10;
}

/**
 * 整体思路
 *    序列的前10位是0~9这10个只有一"位的数字。显然第1001 位在这10个数字之后，因此这10个数字可以直接跳过。
 * 我们再从后面紧跟着的序列中找第991 (991=1001-10) 位的数字。
 *    接下来180位数字是90个10~99的两位数。由于991>180，所以第991位在所有的两位数之后。
 * 我们再跳过90个两位数，继续从后面找881(881=991-180)位。
 *    接下来的2700位是900个100~999的三位数。由于811<2700，所以第811位是某个三位数中的一位。
 * 由于811=270X3+1,这意味着第811位是从100开始的第270个数字即370的中间一位，也就是7。
 */ 
int GetDigitAtIndex(int index) {
    if (index < 0)
        return -1;
    int digits = 1;     // 用来表示几位数字
    while (true) {
        int numbers = CountOfIntegers(digits);  // 计算当前digits位的数共有多少个
        if (index < numbers * digits)
            return DigitAtIndex(index, digits);
        index -= digits * numbers;
        digits++;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    cout << GetDigitAtIndex(n) << endl;
    return 0;
}