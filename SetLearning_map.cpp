#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    map<string, size_t> word_count; 
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word && word != "-1") {
        // 只统计不在exclude中的单词
        if (exclude.find(word) == exclude.end())
            word_count[word]++;     // 获取并增加word的计数器
    }

    // 使用迭代器打印输出 map
    map<string, size_t>::iterator iter;
    for (iter = word_count.begin(); iter != word_count.end(); iter++) {
        cout << iter->first << " occurs " << iter->second
             << ((iter->second) > 1 ? " times" : " time") << endl;
    }
    cout << endl;
    return 0;
}