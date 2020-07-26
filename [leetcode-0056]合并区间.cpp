/**
 * Creation         :       2019.07.27 17:58
 * Last Reversion   :       2019.07.28 18:10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
merge (合并区间)
给出一个区间的集合，请合并所有重叠的区间。

示例 1:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res = {intervals[0]};
    for (int i = 1; i < intervals.size(); i++) {
        if (res.back()[1] < intervals[i][0])
            res.push_back(intervals[i]);
        else 
            res.back()[1] = max(res.back()[1], intervals[i][1]);
    }
    return res;
}

int main () {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = merge(intervals);
    cout << "{";
    for (int i = 0; i < res.size(); i++) {
        cout << "{" << res[i][0] << "," << res[i][1] << "}";
        if (i != res.size() - 1) 
            cout << ",";
    }
    cout << "}" << endl;
    return 0;
}