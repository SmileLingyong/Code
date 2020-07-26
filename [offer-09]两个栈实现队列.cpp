/**
 * Creation         :       2019.03.11 16:03
 * Last Reversion   :       2019.03.11 16:10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * CQueue(两个栈实现队列)
 * 题目描述
 *    用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

stack<int> stack1;
stack<int> stack2;

/* 这题不用考虑栈满的情况 */
void push(int node) {
    stack1.push(node);       // S1用于进栈
}

int pop() {
    int data;
    if (stack2.empty()) {    // S2空，S1非空，将S1出栈压入S2
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }           
    data = stack2.top();     // S2 非空的时候，直接出栈即可
    stack2.pop();
    return data;
}

int main() {
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    
    return 0;
}
