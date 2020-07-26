/**
 * Creation         :       2019.07.19 00:41
 * Last Reversion   :       2019.07.19 11:04
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
ReverseSentence (翻转单词顺序)
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确
的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 方法一：先翻转整个字符串，然后再将每个单词翻转即可
 */ 
string ReverseSentence(string str) {
    reverse(str.begin(), str.end());
    int i = 0, l, r, length = str.size();
    while (i < length) {
        l = i;
        r = i;
        while (i < length && str[i] != ' ') {
            r++;
            i++;
        } 
        reverse(str.begin() + l, str.begin() + r);
        i++;
    }
    return str;
}

int main() {
    string str = "I am a student.";
    cout << ReverseSentence(str) << endl;
    return 0;
}
