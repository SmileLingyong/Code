/**
 * Creation         :       2019.04.21 11:28
 * Last Reversion   :       2019.04.21 16:00
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * GetLeastNumbersSolution(最小的K个数)
 * 题目描述
 *    输入n个整数，找出其中最小的K个数。例如输入 4,5,1,6,2,7,3,8 这8个数字，
 * 则最小的4个数字是1,2,3,4
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/**
 * 方法一：
 *    先升序排序，然后取前k个数 
 * 时间复杂度：O(nlogn)
 */ 
vector<int> GetLeastNumbersSolution(vector<int> input, int k) {
    if (k <= 0 || k > input.size())  return {};
    vector<int> res;
    sort(input.begin(), input.end());
    res.assign(input.begin(), input.begin() + k);
    return res;
}

/**
 * 方法二：
 *    大根堆方法，取前k个数，构建大根堆res，然后将后面的数，依次与堆顶比较，如果比堆顶小，则将其与堆顶交换（具体的交换方法是，先将堆顶出堆，然后
 * 将小的数加入，重新构造大根堆）
 * 时间复杂度：O(nlogk)
 */ 
vector<int> GetLeastNumbersSolution2(vector<int> input, int k) {
    int len = input.size();
    if (len <= 0 || k <= 0 || k > len) {
        return vector<int>();
    }
    // 取前k个构建大根堆
    vector<int> res(input.begin(), input.begin() + k);
    make_heap(res.begin(), res.end());
    
    for (int i = k; i < len; i++) {
        if (res[0] > input[i]) {
            // 弹出堆顶元素
            pop_heap(res.begin(), res.end());   // 交换*first和*(last-1)， 然后把[first, last-1)建成一个max heap. 也就是说把堆顶的最大元素交换到区间尾，然后把除了尾部的元素的剩余区间重新调整成堆。
            res.pop_back();                     // 删除最后一个元素，即原来的堆顶元素
            // 先在容器中加入，再push，构建大根堆
            res.push_back(input[i]);            
            push_heap(res.begin(), res.end());
        }
    }
    // 使其从小到大输出，调用该函数后，就不是大根堆的结构了
    sort_heap(res.begin(), res.end());
    return res;
}

/**
 * 方法三：
 *    小根堆方法
 * 时间复杂度 O(nlogn)
 */ 
static bool Comp(const int &a,const int &b) {   // 牛客网，需要加上static才能通过
    return a > b;
}

vector<int> GetLeastNumbersSolution3(vector<int> input, int k) {
    if (k <= 0 || k > input.size())  return {};
    vector<int> res;

    // 构建小根堆
    make_heap(input.begin(), input.end(), Comp);
    for (int i = 0; i < k; i++) {
        res.push_back(input[0]);                        // 小根堆，堆顶元素
        pop_heap(input.begin(), input.end(), Comp);     // 将堆顶元素移动到末尾，然后将现在的[first, last-1]元素重新构造一个堆    
        input.pop_back();                               // 删除原堆顶元素
    }
    return res;
}

/**
 * 方法四：(这个方法不熟，要补充学习)
 *    红黑树：multiset集合，利用仿函数改变排序顺序，其实就是大根堆的方法
 * 时间复杂度O（nlogk）
 */ 
vector<int> GetLeastNumbersSolution4(vector<int> input, int k) {
    if (k <= 0 || k > input.size())  return {};
    
    // 仿函数中的greater<T> 模板，从大到小排序
    multiset<int, greater<int> > res;
    vector<int>::iterator vec_it;
    for (vec_it = input.begin(); vec_it != input.end(); vec_it++) {
        // 将前k个元素插入集合
        if (res.size() < k)
            res.insert(*vec_it);
        else {
            // 第一个元素是最大值
            multiset<int, greater<int> >::iterator greatest_it = res.begin();
            // 如果后续元素 < 第一个元素，删除第一个，加入当前元素
            if (*vec_it < *(res.begin())) {
                res.erase(greatest_it);
                res.insert(*vec_it);
            }
        }
    }
    return vector<int>(res.begin(), res.end());
}

int main() {
    int k;
    string str;
    vector<int> arr, res;
    cin >> k;       // 最小的前k个数
    cin >> str;
    const char *split = ",";
    char *s_input = (char*)str.c_str();
    char *p = strtok(s_input, split);
    int num;
    while (p != NULL) {
        sscanf(p, "%d", &num);
        arr.push_back(num);
        p = strtok(NULL, split);
    }
    res = GetLeastNumbersSolution4(arr, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}