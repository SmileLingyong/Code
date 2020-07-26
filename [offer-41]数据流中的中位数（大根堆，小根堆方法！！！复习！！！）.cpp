/**
 * Creation         :       2019.04.21 16:20
 * Last Reversion   :       2019.04.21 16:37
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * [offer-41]MedianInTheDataStream(数据流中的中位数)
 * 题目描述
 *    如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数
 * 就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数
 * 就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用
 * GetMedian()方法获取当前读取数据的中位数。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/* -------------------- 方法一，每次插入重新排序 ----------------- */
// vector<int> res = {1, 2, 3, 4, 5};  // C++ 11才能使用
vector<int> res;

void Insert(int num) {
    res.push_back(num);
    sort(res.begin(), res.end());
}

double GetMedian() { 
    int len = res.size();
    if (len & 1) {
        return (double)(res[len / 2]);
    } else {
        return (double)((res[len/2] + res[len/2 - 1]) / 2.0);
    }
}


/* -------------------- 方法二，使用大根堆小根堆实现 ----------------- */
/* 优先队列，函数原型 template < class T, class Container = vector<T>, class Compare = less<typename Container::value_type> > 
它的模板声明带有三个参数，priority_queue<Type, Container, Functional>
Type 为数据类型， Container 为保存数据的容器，Functional 为元素比较方式。
Container 必须是用数组实现的容器，比如 vector, deque 但不能用 list. STL里面默认用的是 vector. 比较方式默认用 operator< , 所以如果你把后面俩个
参数缺省的话，优先队列就是大顶堆，队头元素最大。
*/
priority_queue<int, vector<int>, less<int>> p;      // 小根堆
priority_queue<int, vector<int>, greater<int>> q;   // 大根堆

/**
 * 用一个大顶堆和一个小顶堆，维持大顶堆的数都小于等于小顶堆的数，且两者的个数相等或差1。
 * 即大顶堆的最大数，都比小顶堆的最小数小，即保证容器左边的数都小于右边的数，即使左右两边未排序
 * 可以得到
 * 平均数就在两个堆顶的数之中。
 */ 
void Insert2(int num) {
    if (p.empty() || num <= p.top())
        p.push(num);
    else 
        q.push(num);
    if (p.size() == q.size() + 2) {
        q.push(p.top());    // 每次插入大顶堆q的是当前小顶堆中最小的数
        p.pop();
    }
    if (p.size() + 1 == q.size()) {
        p.push(q.top());    // 每次插入小顶堆p的是当前大顶堆中最大的数
        q.pop();
    }
}

double GetMedian2() {
    return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
}

int main() {
    int x;
    double median;
    while (cin >> x && x != -1) {
        Insert(x);
        median = GetMedian();
    }
    cout << median << endl;
    return 0;
}
