#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

/**
 * 定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子（们）的名。
 * 编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。
 */ 
void AddFamily(map<string, vector<string>> &family) {
    string last_name, first_name;
    while (cout << "Last name:\n" << endl, cin >> last_name && last_name != "-1") {
        while (cout << "|-Children's names:\n" << endl, cin >> first_name && first_name != "-1")
            family[last_name].push_back(first_name);
    }
}

/**
 * 打印输出家族
 */ 
void PrintFamily(map<string, vector<string> > &family) {
    for (map<string, vector<string> >::iterator iter = family.begin(); iter != family.end(); iter++) {
        cout << "The " << (*iter).first << " family is:" << endl;
        for (vector<string>::iterator it = (*iter).second.begin(); it != (*iter).second.end(); it++) {
            cout << (*iter).first << " " << (*it) << endl;
        }
        cout << endl;
    }
}

int main() {
    /* -----------------    map 定义和初始化   ------------------------ */
    // 以下介绍了3中定义map的方法
    map<string, size_t> word_count;                             // （1）定义一个空的map对象
    map<string, size_t> word_count2(word_count);                // （2）创建了 word_count的副本
    map<string, size_t> word_count3(word_count.begin(), word_count.end());  // （3）创建了map对象m，并且存储迭代器范围内的所有元素的副本
    string word;
    while (cin >> word && word != "-1") 
        word_count[word]++;

    /* ----------------- map 插入元素： insert()法 和 下标法 ------------------------ */
    // （1）insert()简单插入
    word_count.insert(make_pair("a", 4));                       // 当map中已经存在"a"这个key值，insert()方法无法插入
    word_count.insert(pair<string, size_t>("b", 3));            // pair方式和make_pair功能是一样的

    // （2）insert()使用迭代器进行插入
    word_count.insert(word_count.begin(), make_pair("c", 2));   

    // （3）当key是int类型时，还可以使用下标插入                      // 注意使用下标插入时，如果不存在该key，则直接插入key-val
                                                                // 若map中存在该key,则会覆盖原先的

    // 判断是否能够插入
    pair<map<string, size_t>::iterator, bool> ret;
    ret = word_count.insert(make_pair("d", 1));
    if (ret.second == false) {
        cout << "element 'd' already existed";
        cout << " with a value of " << ret.first->second << '\n';
    }

    /* ----------------- map 查找元素 find() ------------------------ */
    map<string, size_t>::iterator iter;
    iter = word_count.find("b");
    if (iter != word_count.end()) {
        cout << "erase <\"b\", size_t>" << endl;
        word_count.erase(iter);                             // （1）删除迭代器位置元素
    }

    /* ----------------- map 删除元素 erase() ------------------------ */
    // 共有三种方式来进行删除
    cout << "erase <\"d\", size_t>" << endl;
    word_count.erase("d");                                  // （2）使用key删除
    cout << "erase all key and value" << endl;
    word_count.erase(word_count.begin(), word_count.end()); // （3）删除迭代器范围内元素


    /* ----------------- map 打印输出 ------------------------ */
    // 使用迭代器打印输出 map
    for (iter = word_count.begin(); iter != word_count.end(); iter++) {
        cout << iter->first << " occurs " << iter->second
             << ((iter->second) > 1 ? " times" : " time") << endl;
    }
    cout << endl;

    /* ----------------- map 课后习题11.7 ------------------------ */
    map<string, vector<string> > family;
    AddFamily(family);
    PrintFamily(family);

    /* ----------------- map 课后习题11.32 ------------------------ */
    // 编写程序，定义一个作者及其作品的multimap。使用find在multimap中查找一个元素并用erase删除它。
    // 确保你的程序在元素不在map 中时也能正常运行。
    std::multimap<string, string> authors{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency" } };

	string author = "pezy";
    string work = "CP5";

    auto found = authors.find(author);
    auto count = authors.count(author);
    while (count) {
        if (found->second == work) {
            authors.erase(found);
            break;
        }
        ++found;
        --count;
    }

    for (const auto &author : authors) {
        cout << author.first << " " << author.second << endl;
    }
    
    /* ----------------- map 课后习题11.32 ------------------------ */
    // 使用上一题定义的multimap 编写一个程序，按字典序打印作者列表和他们的作品。
	map<string, multiset<string>> order_authors;

    for (const auto &author : authors) {
        order_authors[author.first].insert(author.second);
    }

    for (const auto &author : order_authors) {
        cout << author.first << ": ";
        for (const auto &word : author.second)
            cout << word << " ";
        cout << endl;
    }


    return 0;
}