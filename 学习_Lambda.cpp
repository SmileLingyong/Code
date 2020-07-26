#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

/**
 * 如果 ctr 的值大于1，返回word的复数形式
 */ 
string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

/**
 * 字符串 str_a 的长度是否小于字符串 str_b 的长度
 */ 
inline bool IsShorter(string const &str_a, string const &str_b) {
    return str_a.size() < str_b.size();
}

/**
 * 10.24 判断字符串长度是否大于 sz
 */ 
bool CheckSize(const string &s, size_t sz) {
    return s.size() > sz;
}

/**
 * 10.13 判断字符串长度是否大于等于 5
 */
bool Predicate(const string &s) {
    return s.size() >= 5;
}
                               
/**
 * 将words按字典顺序排序，删除重复单词
 */ 
void ElimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

/**
 * 按字典顺序将容器排序，并打印出长度大于等于 sz 的string
 */ 
void Biggies(vector<string> &words, vector<string>::size_type sz) {
    // 将words按字典顺序排序，删除重复单词
    ElimDups(words);    

    // 按长度排序，长度相同的单词维持字典顺序
    stable_sort(words.begin(), words.end(), 
                [](const string &a, const string &b)
                  { return a.size() < b.size(); });
    // 以上这个lambda表达式，和 IsShorter()函数等价, 即上面一行与这下面一行等价
    // stable_sort(words.begin(), words.end(), IsShorter);
                  
    // 获取一个迭代器，指向第一个满足 size() >= sz 的元素
    auto wc = find_if(words.begin(), words.end(),
                        [sz](const string &a)
                            { return a.size() >= sz; });

    // 计算满足 size() >= sz 的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;

    // 打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(wc, words.end(),
             [](const string &s) {cout << s << " "; });
    cout << endl;
}

void BiggiesII(vector<string> &words, vector<string>::size_type sz) {
    ElimDups(words);

    auto wc = stable_partition(words.begin(), words.end(), bind(CheckSize, _1, sz));
    for_each(words.begin(), wc, [](const string &s) { cout << s << " "; });
}

/**
 * 10.22 判断字符串长度是否 <= sz
 */ 
bool IsLesserThanOrEqualTopSZ(const string &s, string::size_type sz) {
    return s.size() <= sz;
}

int main() {
    /* -------------------------------------- lambda 表达式 ----------------------------------------- */
    int sz = 5;     // 定义字符串长度阈值为 5
    vector<string> words = {"the", "quick", "red", "fox", "jumps", 
                            "over", "the", "slow", "red", "turtle"};
    Biggies(words, sz);
    BiggiesII(words, sz);

    // 10.13标准库定义了名为 partition 的算法，它接受一个谓词，对容器内容进行划分，
    // 使得谓词为 true 的值会排在容器的前半部分，而使得谓词为 false 的值会排在后半部分。算法返回一个迭代器，
    // 指向最后一个使谓词为 true 的元素之后的位置。编写函数，接受一个 string，返回一个 bool 值，指出 string 
    // 是否有5个或更多字符。使用此函数划分 words。打印出长度大于等于5的元素。
    auto pivot = partition(words.begin(), words.end(), Predicate);  // 这里不好的就是Predicate函数写死了长度为5，而lambda表达式可以很好的处理这个问题！
    
    // 10.18 用lambda表达式重写 partition 方法
    // auto pivot = partition(words.begin(), words.end(), 
    //                         [sz](const string &a)
    //                             { return a.size() >= sz; });

    // 10.19 用 stable_partition 重写前一题的程序，与 stable_sort 类似，在划分后的序列中维持原有元素的顺序。
    // auto pivot = stable_partition(words.begin(), words.end(),
    //                             [sz](const string &a) {return a.size() >= sz; });
    
    for (auto it  = words.begin(); it != pivot; ++it)
        cout << *it << " ";
    cout << endl;

    // 10.14 编写一个lambda，接受两个 int，返回他们的和
    auto sum = [](const int &a, const int &b){ return a + b; };

    // 10.15 编写一个 lambda ，捕获它所在函数的 int，并接受一个 int参数。lambda 应该返回捕获的 int 和 int 参数的和
    int x = 10;
    auto sumII = [x](int i) { i + x; };

    // 10.20 标准库定义了一个名为 count_if 的算法。类似 find_if，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，
    // 会对输入范围中每个元素执行。count_if返回一个计数值，表示谓词有多少次为真。使用count_if重写我们程序中统计有多少单词长度超过5的部分。
    cout << "Length longther than 5' num is " << 
        count_if(words.begin(), words.end(), 
             [sz](const string &s) { return s.size() > sz; }) << endl;
    
    // 10.21 编写一个 lambda，捕获一个局部 int 变量，并递减变量值，直至它变为0。
    // 一旦变量变为0，再调用lambda应该不再递减变量。lambda应该返回一个bool值，指出捕获的变量是否为0。
    int i = 10;
    auto f = [&i]() -> bool { return (i == 0 ? true : !(i--)); };
    while (!f())
        cout << i << " ";
    cout << endl;
    
    /* -------------------------------------- bind 函数 ----------------------------------------- */
    // 10.22 重写统计长度小于等于6的单词数量的程序，使用函数代替 lambda
    cout << "Length less than 6' num is ";
    cout << count_if(words.begin(), words.end(), bind(IsLesserThanOrEqualTopSZ, _1, sz)) << endl;   // bind函数在头文件 functional中, _n 在命名空间 palceholders中，而 palceholders又在命名空间std中

    // 10.24 给定一个string，使用 bind 和 check_size 在一个 int 的vector 中查找第一个大于string长度的值
    string str = "abcdefg";
    vector<int> arr = {1, 7, 6, 10, 2, 9, 10};
    auto it = find_if(arr.cbegin(), arr.cend(), bind(CheckSize, str, _1));
    if (it != arr.end())
        cout << *it << endl;
    
    // 10.25 使用 check_size 和 bind 重写上面的Biggies函数


    return 0;
}