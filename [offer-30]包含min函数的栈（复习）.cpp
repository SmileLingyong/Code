/**
 * Creation         :       2019.04:13 10:04
 * Last Reversion   :       2019.04:13 10:24
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
包含min函数的栈
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数
（时间复杂度应为O（1））。
思路：（看剑指offer的那张表就可以轻易明白）
看到这个问题, 我们最开始可能会想, 添加一个成员变量用于保存最小元素, 
每次压栈时如果压栈元素比当前最小元素更小, 就更新最小元素. 
但是这样会有一个问题, 如果最小元素被弹出了呢, 如何获得下一个最小元素呢? 
分析到这里可以发现, 仅仅添加一个成员变量存放最小元素是不够的, 我们需要在
最小元素弹出后还能得到次小元素, 次小的弹出后, 还要能得到次次小的. 
因此, 用另一个栈来保存这些元素是再合适不过的了. 我们叫它最小元素栈. 
每次压栈操作时, 如果压栈元素比当前最小元素更小, 就把这个元素压入最小元素栈, 
原本的最小元素就成了次小元素. 同理, 弹栈时, 如果弹出的元素和最小元素栈的栈
顶元素相等, 就把最小元素的栈顶弹出.
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <stack>
using namespace std;

stack<int> stack1, stack2;

/**
 * 每次输入一个数据，数据栈和辅助站都要压入数据
 * 数据栈压入输入的数据；辅助栈压入当前最小的元素
 * 这样保证每次pop出一个数据时，辅助栈顶都是当前最小的元素
 */ 
void push(int value) {
    stack1.push(value);                 // 数据栈压入输入的数据
    if (stack2.empty()) {
        stack2.push(value);
    } else if (value <= stack2.top()) { // 辅助栈压入此时最小的元素
        stack2.push(value);
    } else if (value > stack2.top()) {  // 辅助栈压入此时最小的元素
        stack2.push(stack2.top());
    }
}
void pop() {
    stack1.pop();
    stack2.pop();
}
int top() {
    return stack1.top();
}
int min() {
    return stack2.top();
}

int main() {

    return 0;
}