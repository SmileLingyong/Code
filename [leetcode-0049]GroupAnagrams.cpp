/**
 * Creation         :       2019.05.09 13:09
 * Last Reversion   :       2019.05.09 13:46
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * GroupAnagrams(字母异位词分组)
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/**
 * 方法一：使用set，用strs_sort拷贝一份strs，然后将strs_sort中的每个元素先排好序，一一扔进set中
 * 就得到了有几个分组，然后再用这几个分组进行遍历，strs_sort，分别计算每一分组，将原始的strs对应元
 * 素扔进每一个分组
 */ 
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    vector<string> strs_sort = strs;
    set<string> strs_set;
    for (int i = 0; i < strs_sort.size(); i++) {
        sort(strs_sort[i].begin(), strs_sort[i].end());
        strs_set.insert(strs_sort[i]);
    }

    for (set<string>::iterator iter = strs_set.begin(); iter != strs_set.end(); iter++) {
        vector<string> cur_vec;
        for (int j = 0; j < strs_sort.size(); j++) {
            if (strs_sort[j] == *iter) {
                cur_vec.push_back(strs[j]);
            }
        }
        res.push_back(cur_vec);
    }
    return res;
}

/**
 * 方法二：使用under_map 无序无重复的map
 * map的第key值为strs每个元素排序后的值，val为未排序的strs元素值
 * 即同一组的元素就可以存放进vector中
 */ 
vector<vector<string>> groupAnagramsII(vector<string>& strs) {
    unordered_map<string, vector<string> > mp;
    for (string s : strs) {
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }

    vector<vector<string> > res;
    for (auto p : mp) {
        res.push_back(p.second);
    }
    return res;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string> > res = groupAnagrams(strs);
    for (vector<vector<string> >::iterator iter = res.begin(); iter != res.end(); iter++) {
        vector<string>::iterator it;
        for (it = (*iter).begin(); it != (*iter).end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}