/**
 * Creation         :       2019.04.27 15:55
 * Last Reversion   :       2019.04.27 16:05
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * ValidAnagram(有效的数字)
Given two strings s and t , write a function to determine if t is an anagram of s.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 * -----------------------------------------------------------------
 * 思路一：（使用map）
 *    将输入的字符串都用map保存，因为map底层使用的是红黑树实现的，每一次插入都会使用key重新拍好序。
 * 所以，只需要比较这两个map是否相等即可。
 * 
 * 思路二：（排序）
 *    将输入的两个字符串都重新拍好序，然后一一比较即可，如果发现不一样的，则返回false，否则返回true.
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

/**
 * 将字符创用map保存
 */ 
map<char, int> GetStrMap(string &str) {
    map<char, int> str_map;
    for (int i = 0; i < str.size(); i++) {
        str_map[str[i]]++;
    }
    return str_map;
}

/**
 * 方法一：（使用map）
 *    比较两个字符串对应的map是否相同
 */ 
bool IsAnagram (string A, string B) { 
    if (A.size() != B.size())
        return false;
    map<char, int> A_map = GetStrMap(A);
    map<char, int> B_map = GetStrMap(B);
    map<char, int>::iterator A_iter = A_map.begin();
    map<char, int>::iterator B_iter = B_map.begin();

    while (A_iter != A_map.end()) {
        if (A_iter->first != B_iter->first || A_iter->second != B_iter->second)
            return false;
        A_iter++;
        B_iter++;
    }
    return true;
}

/**
 * 将字符串进行排序（快排）
 */ 
void SortString(string &str, int l, int r) {
    int i = l, j = r;
    char key;
    if (l < r) {
        key = str[l];
        while (i < j) {
            while (i < j && str[j] > key)
                j--;
            if (i < j) {
                str[i] = str[j];
                i++;
            }
            while (i < j && str[i] < key) 
                i++;
            if (i < j) {
                str[j] = str[i];
                j--;
            }
        }
        str[i] = key;
        SortString(str, l, i - 1);
        SortString(str, i + 1, r);
    }
}

/**
 * 方法二：（使用排序方法）
 */ 
bool IsAnagramII(string A, string B) {
    SortString(A, 0, A.size()-1);   // 或者直接使用sort()函数排序 sort(A.begin(), A.end())
    SortString(B, 0, B.size()-1);
    if (A == B)
        return true;
    else
        return false;
}

/**
 * 方法三：（很巧妙的思路）
 *    初始化一个长度为26的数组，因为英文字母有26个，遍历字符串s并用数组的值来记录各个字母出现的个数，
 * 再遍历t，依次比较统计后的字符数目。
 */ 
bool isAnagram(string s, string t) {
	int i, x[26] = { 0 }, y[26] = { 0 };
	for (i = 0; s[i] != '\0'; i++) 	x[s[i] - 'a']++;	// 建立 s 的字符表 x
	for (i = 0; t[i] != '\0'; i++)	y[t[i] - 'a']++;	// 建立 t 的字符表 y
	for (i = 0; i < 26; i++)							// 比较两字符表是否相同
		if (x[i] != y[i])	
            return false;
	return true;										// 种类、个数均相同
}

/**
 * 打印输出
 */ 
void PrintResult(bool res) {
    if (res)
        cout << "Is anagram." << endl;
    else 
        cout << "Isn't anagram." << endl;
}

int main() {
    string A, B;
    cin >> A >> B;
    PrintResult (IsAnagram(A, B));
    PrintResult (IsAnagramII(A, B));
    return 0;
}
