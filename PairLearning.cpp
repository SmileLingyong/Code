
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    string name;
    int age;
    vector<pair<string, int>> vec_person;
    while (cin >> name >> age && name != "-1" && age != -1) {
        /* -----------------    创建 pair 的三种方式   ------------------------ */
        // 创建一个空的 pair
        pair<string, int> pair_person;
        pair_person.first = name;
        pair_person.second = age;
        vec_person.push_back(pair_person);

        // 使用参数初始化，创建pair
        pair<string, int> pair_person(name, age);
        vec_person.push_back(pair_person);

        // 使用 make_pair() 创建 pair
        vec_person.push_back(make_pair(name, age));

        // 列表初始化
        vec_person.push_back({name, age});  // C++ 11特性
    } 
    return 0;
}