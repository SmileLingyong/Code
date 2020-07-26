/*
超长非负求和
输入
两个非负小数或整数

输出
求和的结果
（1）不损失精度
（2）收尾均不出现无意义的0
（3）不出现无意义的小数点（比如 1.00 应该输出 1）
（4）不得使用除字符操作以为的函数
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int A[205], B[205];  // 用来记录整数相加部分和小数相加部分，先不处理进位（这里多开辟了几个空间，防止前面也有进位）

/**
 * 处理字符串，A，B分别保存整数部分和小数部分，
 * 然后将整数部分和小数部分都相应的进行加（暂时先不考虑进位）
 */
void Process(string str) {
    int len = str.size();
    int index = len;
    for (int i = 0; i < len; i++) 
        if (str[i] == '.') {
            index = i;  // 记录小数点位置
            break;  
        }
    int k = 0;
    for (int i = index - 1; i >= 0; i--) 
        A[k++] += (str[i] - '0');
    k = 0;
    for (int i = index + 1; i < len; i++) 
        B[k++] += (str[i] - '0');
}

string add(string &a1, string &a2) {
    int len1 = a1.size();
    int len2 = a2.size();
    int x1 = 0, x2 = 0;     // 分别记录A中整数开始位置x1，和B中小数结束的位置x2
    bool has_point = false;
    int pre = 0;
    string res = "";
    // 处理小数部分
    for (int i = 200; i >= 0; i--) {    // 从后往前，处理相加后的小数位，不断处理进位
        B[i] += pre;                    // 加上上一次的进位
        pre = B[i] / 10;                // 计算当前进位
        B[i] %= 10;                     // 取余
        if (B[i] != 0 && !has_point) {  // 此时B[i]不为0，则说明找到了小数结尾的位置
            x2 = i;
            has_point = true;           // 标志有小数位
        }
    }
    // 处理整数部分
    for (int i = 0; i < 200; i++) {
        A[i] += pre;                   
        pre = A[i] / 10;
        A[i] %= 10;
        if (A[i] != 0) 
            x1 = i;                     // 记录整数开始的位置（因为是逆序后相加的）
    }
    if (pre != 0) {                     // 若整数最高位还有进位，则再往前更新一位
        A[200] += pre;
        x1 = 200;
    }
    for (int i = x1; i >= 0; i--)       // 保存整数部分
        res += to_string(A[i]);
    if (has_point) {                    // 保存小数部分
        res += '.';
        for (int i = 0; i <= x2; i++)       
            res += to_string(B[i]);
    }
    return res;
}

// please don't modify any code below.
int main() {
    string a1, a2, a3;
    cin >> a1 >> a2;
    Process(a1);
    Process(a2);
    a3 = add(a1, a2);
    cout << a3 << endl;
    return 0;
}