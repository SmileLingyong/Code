/**
 * Creation         :       2019.06.01 15:15
 * Last Reversion   :       2019.06.01 15:38
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * GetPermutation(第k个排列)
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：
给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。

示例 1:
输入: n = 3, k = 3
输出: "213"

示例 2:
输入: n = 4, k = 9
输出: "2314"
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

void Swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void FullyArrange(string &nums, int index, set<string> &res) {
    if (index >= nums.size()) {
        res.insert(nums);
    }
    for (int j = index; j < nums.size(); j++) {
        Swap(nums[j], nums[index]);
        FullyArrange(nums, index + 1, res);
        Swap(nums[j], nums[index]);
    }
}

/**
 * 方法一：先生成全排列，然后再取第k个，超时
 */ 
string getPermutation(int n, int k) {
    set<string> res;
    string res_str;
    string nums = "";
    for (int i = 1; i <= n; i++) 
        nums += to_string(i);
    FullyArrange(nums, 0, res);
    int count = 0;
    for (set<string>::iterator iter = res.begin(); iter != res.end(); iter++) {
        count++;
        if (count == k) {
            res_str = *iter;
            return res_str;
        }
    }
    return res_str;
}

/**
 * 方法二：找规律，这个比较难，要多做几遍才行
 * Reference: 
 *   - https://www.cnblogs.com/grandyang/p/4358678.html
 *   - https://leetcode-cn.com/problems/permutation-sequence/comments/
 * -----------------------------------------------------------------------
直接用回溯法做的话需要在回溯到第k个排列时终止就不会超时了, 但是效率依旧感人
可以用数学的方法来解, 因为数字都是从1开始的连续自然数, 排列出现的次序可以推
算出来, 对于n=4, k=15 找到k=15排列的过程:

1 + 对2,3,4的全排列 (3!个)         
2 + 对1,3,4的全排列 (3!个)         3, 1 + 对2,4的全排列(2!个)
3 + 对1,2,4的全排列 (3!个)-------> 3, 2 + 对1,4的全排列(2!个)-------> 3, 2, 1 + 对4的全排列(1!个)-------> 3214
4 + 对1,2,3的全排列 (3!个)         3, 4 + 对1,2的全排列(2!个)         3, 2, 4 + 对1的全排列(1!个)

确定第一位:
    k = 14(从0开始计数)
    index = k / (n-1)! = 2, 说明第15个数的第一位是3 
    更新k
    k = k - index*(n-1)! = 2
确定第二位:
    k = 2
    index = k / (n-2)! = 1, 说明第15个数的第二位是2
    更新k
    k = k - index*(n-2)! = 0
确定第三位:
    k = 0
    index = k / (n-3)! = 0, 说明第15个数的第三位是1
    更新k
    k = k - index*(n-3)! = 0
确定第四位:
    k = 0
    index = k / (n-4)! = 0, 说明第15个数的第四位是4
最终确定n=4时第15个数为3214 
 
*/ 
string getPermutationII(int n, int k) {
    string res;
    string nums = "123456789";
    vector<int> f(n, 1);
    for (int i = 1; i < n; i++) {
        f[i] = f[i - 1] * i;
    }
    k--;    // 下标从0开始
    for (int i = n; i >= 1; i--) {
        int index = k / f[i - 1];
        k %= f[i - 1];
        res.push_back(nums[index]);
        nums.erase(index, 1);
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k) << endl;;
    cout << getPermutationII(n, k) << endl;;
    return 0;
}