/**
 * Creation         :       2019.05.28 20:59
 * Last Reversion   :       2019.05.28 20:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
checkValidString(有效的括号字符串)
给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

任何左括号 ( 必须有相应的右括号 )。
任何右括号 ) 必须有相应的左括号 ( 。
左括号 ( 必须在对应的右括号之前 )。
* 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
一个空字符串也被视为有效字符串。
示例 1:
输入: "()"
输出: True

示例 2:
输入: "(*)"
输出: True

示例 3:
输入: "(*))"
输出: True
注意:
字符串大小将在 [1，100] 范围内。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/**
方法一：
   这里主要处理*号的问题，我们来判断两种特殊情况，*) 和 *(在第一种情况下，
星号可以当左括号来用，而在第二种情况下，无论星号当左括号，右括号，还是空，*( 都
是不对的。当然这种情况只限于星号和左括号之间的位置关系，而只要星号在右括号前面，
就一定可以消掉右括号。
   那么我们使用两个stack，分别存放左括号和星号的位置，遍历字符串，当遇到星号时，
压入星号栈star，当遇到左括号时，压入左括号栈left，当遇到右括号时，此时如果left
和star均为空时，直接返回false；如果left不为空，则pop一个左括号来抵消当前的右括号；
否则从star中取出一个星号当作左括号来抵消右括号。 
   当循环结束后，我们希望left中没有多余的左括号，就算有，我们可以尝试着用星号来抵消。
当star和left均不为空时，进行循环，如果left的栈顶左括号的位置在star的栈顶星号的右边，
那么就组成了 *( 模式，直接返回false；否则就说明星号可以抵消左括号，各自pop一个元
素。最终退出循环后我们看left中是否还有多余的左括号，没有就返回true，否则false。
 */ 
bool checkValidString(string s) {
    stack<int> left, star;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*')        // 遇到'*'则加入star栈
            star.push(i);
        else if (s[i] == '(')   // 遇到'('则加入left栈
            left.push(i);
        else {                  // 遇到')'
            if (left.empty() && star.empty()) // '(' 和 '*'都为空，返回false
                return false;
            if (!left.empty()) 
                left.pop();
            else 
                star.pop();
        }
    }
    while (!left.empty() && !star.empty()) {    // 遍历完，若 '(' 和 '*' 都不为空
        if (left.top() > star.top())            // 若 '(' 在 '*' 的右边，则返回false
            return false;
        left.pop();                             // 否则，用 '*' 来消掉每一个 '('
        star.pop();
    }
    return left.empty();
}

/**
方法二：（正反都遍历一次的思想）
   既然星号可以当左括号和右括号，那么我们就正反各遍历一次，正向遍历的时候，我们把星号
都当成左括号，此时用经典的验证括号的方法，即遇左括号计数器加1，遇右括号则自减1，如
果中间某个时刻计数器小于0了，直接返回false。如果最终计数器等于0了，我们直接返回true，
因为此时我们把星号都当作了左括号，可以跟所有的右括号抵消。而此时就算计数器大于0了，
我们暂时不能返回false，因为有可能多余的左括号是星号变的，星号也可以表示空。
   我们还需要反向遍历一下，这是我们将所有的星号当作右括号，
遇右括号计数器加1，遇左括号则自减1，如果中间某个时刻计数器小于0了，直接返回false。
遍历结束后直接返回true，这是为啥呢？此时计数器有两种情况，要么为0，要么大于0。为0不
用说，肯定是true，为啥大于0也是true呢？因为之前正向遍历的时候，我们的左括号多了，我
们之前说过了，多余的左括号可能是星号变的，也可能是本身就多的左括号。本身就多的左括号
这种情况会在反向遍历时被检测出来，如果没有检测出来，说明多余的左括号一定是星号变的。
而这些星号在反向遍历时又变做了右括号，最终导致了右括号有剩余，所以当这些星号都当作空
的时候，左右括号都是对应的，即是合法的。你可能会有疑问，右括号本身不会多么，其实不会
的，如果多的话，会在正向遍历中被检测出来.
 */ 
bool checkValidString(string s) {
    int left = 0, right = 0, n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '*') left++;
        else left--;
        if (left < 0) return false;
    }
    if (left == 0) return true;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')' || s[i] == '*') right++;
        else right--;
        if (right < 0) return false;
    }
    return true;
}

int main() {
    string str;
    cin >> str;
    if (checkValidString(str))
        cout << "True";
    else 
        cout << "False";
    return 0;
}