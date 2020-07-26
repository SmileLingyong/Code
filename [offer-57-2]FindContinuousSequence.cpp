/**
 * Creation         :       2019.07.19 00:41
 * Last Reversion   :       2019.07.19 11:04
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
FindContinuousSequence (和为s的连续正数序列)
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了
正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100
(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出：
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从
小到大的顺序
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：使用左右两个指针，因为最少要两个数，所以设置初始left=1, right=2
 * 然后进行计算: 例如：sum = 9
 * (1) 若数组中的和 cur_sum 小于 sum，则再加上右边一个数，得到[1, 2, 3]
 *  ...                                                [1, 2, 3, 4]
 * (2) 若数组中的和 cur_sum 大于 sum，则减去最左边的一个数，得到 [2, 3, 4]
 * (3) 若数组中的和 cur_sum 等于 sum，则添加进out，结果集合，继续加上右边的一个数进行判断
 */ 
vector<vector<int> > FindContinuousSequence(int sum) {
    if (sum < 3) return {};
    int left = 1, right = 2, cur_sum = 3;
    vector<int> res = {1, 2};
    vector<vector<int>> out;
    while (res[res.size()-1] + res[res.size()-2] <= sum) {
        if (cur_sum < sum) {
            right++;
            res.push_back(right);
            cur_sum += right;
        } else if (cur_sum > sum) {
            cur_sum -= res[0];
            res.erase(res.begin());
            left++;
        } else {
            out.push_back(res);
            right++;
            res.push_back(right);
            cur_sum += right;
        }
    }
    return out;
}

int main () {
    int sum = 100;
    vector<vector<int>> res = FindContinuousSequence(sum);
    for (vector<vector<int>>::iterator iter = res.begin(); iter != res.end(); iter++) {
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}