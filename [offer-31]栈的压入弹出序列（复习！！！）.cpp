/**
 * Creation         :       2019.04.13 11:10
 * Last Reversion   :       2019.04.13 11:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
IsPopOrder(栈的压入弹出序列)
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为
该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的
弹出序列。（注意：这两个序列的长度是相等的）
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
【思路】借用一个辅助的栈，遍历压栈顺序，先将第一个放入栈中，这里是1，
然后判断栈顶元素是不是出栈顺序的第一个元素，这里是4，很显然1≠4，所以
我们继续压栈，直到相等以后开始出栈，出栈一个元素，则将出栈顺序向后移动
一位，直到不相等，这样循环等压栈顺序遍历完成，如果辅助栈还不为空，说明
弹出序列不是该栈的弹出顺序。
举例：
入栈1,2,3,4,5
出栈4,5,3,2,1
首先1入辅助栈，此时栈顶1≠4，继续入栈2
此时栈顶2≠4，继续入栈3
此时栈顶3≠4，继续入栈4
此时栈顶4＝4，出栈4，弹出序列向后一位，此时为5，,辅助栈里面是1,2,3
此时栈顶3≠5，继续入栈5
此时栈顶5=5，出栈5,弹出序列向后一位，此时为3，,辅助栈里面是1,2,3
….
依次执行，最后辅助栈为空。如果不为空说明弹出序列不是该栈的弹出顺序。
*/
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    if (pushV.size() == 0)
        return false;
    stack<int> stk;
    // 用于表示弹出序列的位置 
    int pop_idx = 0;
    for (int i = 0; i < pushV.size(); i++) {
        stk.push(pushV[i]);
        while (!stk.empty() && stk.top() == popV[pop_idx]) {
            // 辅助栈出栈
            stk.pop();
            // 弹出序列向后一位
            pop_idx++;
        }
    }
    return stk.empty(); // 若辅助栈不为空，则说明不存在该出栈顺序
}

int main() {
    int arr_pushV[] = {1, 2, 3, 4, 5};
    int arr_popV[] = {4, 5, 3, 2, 1};
    vector<int> pushV(arr_pushV, arr_pushV + sizeof(arr_pushV) / sizeof(int));
    vector<int> popV(arr_popV, arr_popV + sizeof(arr_popV) / sizeof(int));
    if (IsPopOrder(pushV, popV)) {
        cout << "Exist this pop order!" << endl;
    } else {
        cout << "Dont't exist this pop order!" << endl;
    }
    return 0;
}