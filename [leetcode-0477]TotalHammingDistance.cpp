/**
 * Creation         :       2019.05.09 21:23
 * Last Reversion   :       2019.05.09 21:23
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * TotalHammingDistance(汉明距离总和)
两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

计算一个数组中，任意两个数之间汉明距离的总和。

示例:

输入: 4, 14, 2

输出: 6

解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
注意:

数组中元素的范围为从 0到 10^9。
数组的长度不超过 10^4。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief: 计算两个整数的Hamming距离
 * 方法一：
 *    使用异或^，对两个整数a,b进行异或操作得到整数c，然后判断c每一位二进制位，
 * 如果为1，则说明原来两个数二进制数位不同。
 */ 
int totalHammingDistanceTwoNum(int a, int b) {
    int c = a ^ b;
    int count = 0;
    while (c) {
        if (c % 2 == 1)
            count++;
        c >>= 1;
    }
    return count;
}

/**
 * @brief: 计算两个整数的Hamming距离
 * 方法二：（使用 n & (n-1)技巧，其可以将n的二进制数表示中排在最后的一个1，变为0，即达到消掉一个1目的）
 *    使用异或^，对两个整数a,b进行异或操作得到整数c，然后判断c每一位二进制位，
 * 然后每次使用 c & (c - 1) 消掉c二进制表示中，最后一个1，直到所有的c为0，即统计了所有的1
 */ 
int totalHammingDistanceTwoNumII(int a, int b) {
    int c = a ^ b;
    int count = 0;
    while (c) {
        ++count;
        c &= (c - 1);
    }
    return count;
}

/**
 * @brief: 计算一个数组中，任意两个数之间汉明距离的总和
 * 方法一： 暴力求解（超时）
 */ 
int totalHammingDistance(vector<int>& nums) {
    if (nums.empty())
        return 0;
    int total_sum = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            total_sum += totalHammingDistanceTwoNum(nums[i], nums[j]);
        }
    }
    return total_sum;
}

/**
 * @brief: 计算一个数组中，任意两个数之间汉明距离的总和
 * 方法二： 找规律
这道题是之前那道Hamming Distance的拓展，由于有之前那道题的经验，我们知道需要用异或来求每个位上的情况，
那么我们需要来找出某种规律来，比如我们看下面这个例子，4，14，2和1：
4:     0 1 0 0
14:    1 1 1 0
2:     0 0 1 0
1:     0 0 0 1

我们先看最后一列，有三个0和一个1，那么它们之间相互的汉明距离就是3，即1和其他三个0分别的距离累加，
然后在看第三列，累加汉明距离为4，因为每个1都会跟两个0产生两个汉明距离，同理第二列也是4，第一列是3。
我们仔细观察累计汉明距离和0跟1的个数，我们可以发现其实就是0的个数乘以1的个数，发现了这个重要的规律，
那么整道题就迎刃而解了，只要统计出每一位的1的个数即可，参见代码如下：
 */ 
int totalHammingDistanceII(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        int cnt = 0;
        for (auto num : nums) {
            if (num & ( 1 << i))  cnt++;
        }
        res += cnt * (nums.size() - cnt);   // 每一位1的个数 * 0的个数
    }
    return res;
}

int main() {
    int a, b, c;
    cin >> a >> b;
    cout << "a and b result is: " << totalHammingDistanceTwoNumII(a, b) << endl;;
    cin >> c;
    vector<int> nums = {a, b, c};
    cout << "a b c array result is: " << totalHammingDistanceII(nums) << endl;;
    return 0;
}