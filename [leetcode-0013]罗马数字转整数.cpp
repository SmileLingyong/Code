/**
 * Creation         :       2019.07.02 16:49
 * Last Reversion   :       2019.07.02 16:49
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
romanToInt(罗马数字转整数) 
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，
所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:
输入: "III"
输出: 3

示例 2:
输入: "IV"
输出: 4

示例 3:
输入: "IX"
输出: 9

示例 4:
输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.

示例 5:
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <map>
using namespace std;

/**
 * 方法一：首先简历一个HashMap来映射符号和值，然后对字符串从左到右来读：
 * 如果当前字符代表的值不小于其右边，就加上该值；
 * 否则，就减去该值。
 */ 
int romanToInt(string s) {
    // 构建映射字典
    map<char, int> dict;
    dict.insert(make_pair('M', 1000));
    dict.insert(make_pair('D', 500));
    dict.insert(make_pair('C', 100));
    dict.insert(make_pair('L', 50));
    dict.insert(make_pair('X', 10));
    dict.insert(make_pair('V', 5));
    dict.insert(make_pair('I', 1));

    int len = s.size();
    int res = 0;
    for (int i = 0; i < len; i++) {
        if (i + 1 < len && dict[s[i]] < dict[s[i + 1]]) {
            res -= dict[s[i]];
        } else {
            res += dict[s[i]];
        }
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << romanToInt(str) << endl;
    return 0;
}
