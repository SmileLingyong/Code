/**
 * Creation         :       2019.07.25 19:06
 * Last Reversion   :       2019.07.25 20:11
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
LastRemaining (孩子们的游戏-圆圈中最后剩下的数)
0, 1, ..., n-1 这 n 个数字排成一个圆圈，从数字 0 开始，每次从这个圆圈里删除第
m 个数字。求这个圆圈里剩下的最后一个数字。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * 方法一：直接遍历即可 （借助一个数组）
 * 时间复杂度：O(n*m)
 */ 
int LastRemaining_Solution(int n, int m) {
    if (n < 1 || m < 1) return -1;
    
    // 每个人的编号
    vector<int> a;
    for (int i = 0; i < n; i++) {
        a.push_back(i);
    }

    // 开始游戏，循环报数，终止条件是只剩下一个小孩
    int i = -1, step = 0, count = n;
    while (count > 0) {
        i++;                        // 当前报到的下标，也即每个人的数
        if (i >= n)                 // 转到最后一个后一个即回到起点
            i = 0;
        if (a[i] == -1) continue;   // 跳过被删除的对象
        step++;                     // 报号计数器
        if (step == m) {            // 报号到m个
            a[i] = -1;              // 将这个数出队
            step = 0;               // 报号计数器重新置为0
            count--;                // 人数-1
        }
    }
    return i;
}

/**
 * 方法二：使用 erase()每次报道m，就删除该元素，但是vector每次删除后都会将后面的元素前移
 * 所以效率非常低，不建议使用这种方法操作！
 */ 
int LastRemaining_SolutionII(int n, int m) {
    if (n < 1 || m < 1) 
        return -1;

    // 每个人的编号
    vector<int> a;
    for (int i = 0; i < n; i++) {
        a.push_back(i);
    }

    int i = -1, step = 0, count = n; 
    while (count > 1) {
        i++;
        if (i >= a.size()) {
            i = 0;
        }
        step++;
        if (step == m) {
            a.erase(a.begin() + i);
            step = 0;
            count--;
            i--;    // 注意使用erase删除了第i个元素，后面i+1 到end的元素都会前移一个位置，所以我们的i要--，下次好再++
        }
    }
    return a[0];
}

/**
方法三：找规律，其实就是动态规划
我们知道第一个人(编号一定是m%n-1) 出列之后，剩下的n-1个人组成了一个新的约瑟夫环（以编号为k = m % n的人开始）:
k  k+1  k+2  ... n-2, n-1, 0, 1, 2, ... k-2并且从k开始报0
现在我们把他们的编号做一下转换：
k     --> 0
k+1   --> 1
k+2   --> 2
...
...
k-2   --> n-2
k-1   --> n-1
变换后就完完全全成为了(n-1)个人报数的子问题，假如我们知道这个子问题的解： 例如x是最终的胜利者，那么根据上面这个
表把这个x变回去不刚好就是n个人情况的解吗.变回去的公式很简单，相信大家都可以推出来：左边 x'=(x+k)%n

令f[i]表示i个人玩游戏报m退出最后胜利者的编号，最后的结果自然是f[n]。
递推公式
        f[1]=0;
        f[i]=(f[i-1]+m)%i;  (i>1)
有了这个公式，我们要做的就是从1-n顺序算出f[i]的数值，最后结果是f[n]。 因为实际生活中编号总是从1开始，我们输出f[n]+1。
 */ 
int LastRemaining_SolutionIII(int n, int m) {
    if (n < 1 || m < 1) 
        return -1;
    int last = 0;
    for (int i = 2; i <= n; i++) {
        last = (last + m) % i;
    }
    return last;
}

/**
 * 方法三的递归版本
 */ 
int LastRemaining_SolutionIV(int n, int m) {
    if (n < 1 || m < 1) 
        return -1;
    if (n == 1)
        return 0;
    else 
        return (LastRemaining_SolutionIV(n - 1, m) + m) % n;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << LastRemaining_Solution(n, m) << endl;
    cout << LastRemaining_SolutionII(n, m) << endl;
    cout << LastRemaining_SolutionIII(n, m) << endl;
    cout << LastRemaining_SolutionIV(n, m) << endl;
    return 0;
}