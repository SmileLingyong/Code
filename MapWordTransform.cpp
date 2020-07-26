#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
using namespace std;

map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;  // 保存转换规则
    string key;
    string value;
    // 读取第一个单词存入key中，行中剩余内容存入value
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);   // 跳过前导空格
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = buildMap(map_file);        // 保存转换规则
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        
    }

}

int main() {

    return 0;
}