/**
 * Creation         :       2019.05.29 17:37
 * Last Reversion   :       2019.05.29 17:47
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
permute(全排列)
给定一个没有重复数字的序列，返回其所有可能的全排列。
示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 * ----------------------------------------------------------------
 * 思路：
 *    123的全排列有123、132、213、231、312、321这六种。首先考虑213和321
 * 这二个数是如何得出的。显然这二个都是123中的1与后面两数交换得到的。然后
 * 可以将123的第二个数和每三个数交换得到132。同理可以根据213和321来得231
 * 和312。因此可以知道——全排列就是从第一个数字起每个数分别与它后面的数字交
 * 换。找到这个规律后，递归的代码就很容易写出来了
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

/**
 * 方法一：递归写法
 */ 
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<vector<int>> permute_core(vector<vector<int>> &res, vector<int> &nums, int index) {
    if (index >= nums.size()) {
        res.push_back(nums);
    }
    for (int j = index; j < nums.size(); j++) {
        swap(nums[j], nums[index]);
        permute_core(res, nums, index + 1);
        swap(nums[j], nums[index]);
    }
    return res;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res;
    permute_core(res, nums, 0);
    return res;
}

/**
 * 方法二：使用C++STL的内置函数 next_permutation()，专门返回一个全排列
 */ 

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>> res = permute(nums);
    for (vector<vector<int>>::iterator iter = res.begin(); iter != res.end(); iter++) {
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it++) {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}