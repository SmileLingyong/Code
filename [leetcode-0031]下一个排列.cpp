/**
 * Creation         :       2019.06.01 11:38
 * Last Reversion   :       2019.06.01 11:38
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * nextPermutation(下一个排列)
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
思路：
求下一个排列顺序，如果给定数组是降序，则说明是全排列的最后一种情况，则下一个排列就是最初始情况
看一般的情况，如果一个数组：
1　　2　　7　　4　　3　　1
下一个排列为：
1　　3　　1　　2　　4　　7
从末尾往前看，数字逐渐变大，到了2时才减小的，然后我们再从后往前找第一个比2大
的数字，是3，那么我们交换2和3，再把此时3后面的所有数字转置一下即可，步骤如下：

1   (2)　　7　　4　　 3　　 1

1　　(2)　　7　　4　　(3)　　1

1　　(3)　　7　　4　　(2)　　1

1　　 3　　(1)　(2)　(4)　 (7)
*/ 
void nextPermutation(vector<int>& nums) {
    int i, j, temp;
    // 一般情况
    for (i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i+1]) {
            for (j = nums.size() - 1; j > i; j--) {
                if(nums[j] > nums[i]) {
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    reverse(nums.begin()+i+1, nums.end());
                    return;
                }
            }
        }
    }
    // 第一种情况，给定数组就是降序的
    reverse(nums.begin(), nums.end());
}


int main() {
    vector<int> nums = {1, 2, 7, 4, 3, 1};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}