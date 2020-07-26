/**
 * Creation         :       2019.07.19 12:20
 * Last Reversion   :       2019.07.19 12:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
maxInWindows (滑动窗口的最大值)
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组
{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别
为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
{2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
int MaxValue(const vector<int>& num, int l, int r);

/**
 * 方法一：遍历即可 （超时！）
 * 时间复杂度： O(num * size)
 */
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    int length = num.size();
    if (length == 0 || size <= 0 || length < size) return {};
    vector<int> res;
    for (int i = 0; i < length - size + 1; i++) {
        res.push_back(MaxValue(num, i, i + size));
    }
    return res;
}

int MaxValue(const vector<int>& num, int l, int r) {
    int max_val = num[l];
    for (int i = l + 1; i < r; i++) {
        max_val = max(max_val, num[i]);
    }
    return max_val;
}

/**
 * 方法二：使用双端队列 
 * 时间复杂度为O(n)
 */
vector<int> maxInWindowsII(const vector<int>& num, unsigned int size) {
    vector<int> res;
    deque<int> s;
    int length = num.size();
    if (length == 0 || size <= 0 || length < size) return {};
    for (unsigned int i = 0; i < num.size(); ++i) {
        while (s.size() && num[s.back()] <= num[i])     // 从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
            s.pop_back();
        while (s.size() && i - s.front() + 1 > size)    // 当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
            s.pop_front(); 
        s.push_back(i);                                 // 把每次滑动的num下标加入队列
        if (size && i + 1 >= size)                      // 当滑动窗口首地址i大于等于size时才开始写入窗口最大值
            res.push_back(num[s.front()]);
    }
    return res;
}

int main() {
    vector<int> num = {2, 3, 4, 2, 6, 2, 5, 1};
    int size = 3;
    vector<int> res = maxInWindowsII(num, size);
    for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
