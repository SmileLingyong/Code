/**
 * Creation         :       2019.07.26 00:18
 * Last Reversion   :       2019.07.26 00:45
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
IsContinuous (扑克牌顺序)
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,
嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,
决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”
(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,
然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认
为大小王是0。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
方法一：思想如下
1、如果输入为空，返回false
2、除了王的任何某个特定数值的牌出现两张或者更多，那么一定凑不齐顺子。
思路，先统计王的数量，再把牌排序，如果后面一个数比前面一个数大于1以上，那么中间的
差值就必须用王来补了。看王的数量够不够，如果够就返回true，否则返回false。
 */ 
bool IsContinuous(vector<int> numbers) {
    int length = numbers.size();
    if (length <= 0) return false;
    sort(numbers.begin(), numbers.end());   // 先排序
    
    int zero_num = 0, zero_need = 0;        // zero_num 统计0的个数，zero_need需要0的个数
    for (int i = 0; i < length; i++) {
        if (numbers[i] == 0) 
            zero_num++;
        else if (i + 1 < length) {
            if (numbers[i] == numbers[i + 1]) { // 如果有两个一样的数字，则肯定不存在顺子
                return false;
            } else {
                zero_need += numbers[i + 1] - numbers[i] - 1;   // 统计需要0的个数
            }
        }
    }
    if (zero_need > zero_num) return false;
    return true;
}

int main() {
    vector<int> numbers = {1, 2, 3, 5, 0};
    cout << IsContinuous(numbers) << endl;
    return 0;
}