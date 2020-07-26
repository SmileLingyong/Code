/**
 * Creation         :       2019.08.22 00:32
 * Last Reversion   :       2019.08.22 00:32
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
最小栈
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MinStack {
public:
    stack<int> stack1, stack2;

    MinStack() {
        
    }
    
    void push(int x) {
        stack1.push(x);
        if (stack2.empty()) {
            stack2.push(x);
        } else if (x < stack2.top()) {
            stack2.push(x);
        } else if (x >= stack2.top()) {
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
    
    int getMin() {
        return stack2.top();
    }
};

int main() {

    return 0;
}
