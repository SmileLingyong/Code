/**
 * Creation         :       2019.07.21 20:52
 * Last Reversion   :       2019.07.21 20:52
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
PrintProbability (n个骰子的点数)
把n个骰子扔在地上，所有骰子朝上一面的点数之和为 s 。输入 n，打印出 s 的所有可能的值
出现的概率。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int CountNumber(int n, int s);

int g_max_val = 6;

/**
 *  @param start:       起始数字
 *  @param cur_num:     现在是第几个骰子
 *  @param sum:         点数和为多少
 *  @param vec_prob:    idx为： 点数和 - start，没当递归到一个数字的时候， vec就将当前的 vec_prob ++
 */ 
void ProbabilityRec(int start, int cur_num, int sum, vector<int> &vec_prob) {
    if (cur_num == 1) {
        vec_prob[sum - start]++;
    } else {
        for (int i = 1; i <= g_max_val; i++) {
            ProbabilityRec(start, cur_num - 1, i + sum, vec_prob);
        }
    }
}

void Probability(int n, vector<int> &vec_prob) {
    for (int i = 1; i <= g_max_val; i++) {
        ProbabilityRec(n, n, i, vec_prob);
    }
}

/**
方法一： （递归方法）
思想：求出n个骰子的点数和，可以先把n个骰子分为两堆：第一堆只有一个，另一堆有n-1个。
单独的那一个有可能出现 1 ~ 6 的点数。然后计算 1 ～ 6 的每一种点数和剩下的 n-1
个骰子 来计算点数和。接下来把剩下的 n-1 个骰子仍然分成两堆：第一堆只有一个，第二堆有 n-2 个。
把上一轮那个单独的骰子的点数和这一轮单独的骰子点数相加，再和剩下的 n-2个骰子计算点数和。
其实就是递归的思想。递归出口就是最后只剩下一个骰子。（自己Debug一遍就可以理解）
 */
void PrintProbability(int n) {
    if (n < 1) return;
    int max_sum = n * g_max_val;
    vector<int> vec_prob(max_sum - n + 1, 0);   // 开辟一个长度为6n-n+1大小的数组，并初始化为0，存放所有点数之和（6 ～ 6n）

    Probability(n, vec_prob);                   // 递归调用

    int total = pow((double)g_max_val, n);      // 所有点数的排列数为 6^n
    for (int i = n; i <= max_sum; i++) {        // 打印输出，每一种点数和的概率
        double ratio = (double)vec_prob[i - n] / total;
        cout << i << " " << ratio << " " << endl;
    }
}

/**
方法二： 动态规划（递归实现）
① 定义状态：F(n, s) 表示n个骰子点数的和为s的排列总数。
② 状态转移方程：n 个骰子点数和为s的种类数只与 n-1个骰子的和有关。因为骰子有6个点数
那么第n个骰子可能出现1到6的点数。所以第n个骰子的点数为1的话，F(n, s) = F(n-1,s-1)， 
当第n个骰子点数为2的话，F(n, s) = F(n-1, s-2),...,依次类推。在n-1个骰子的基础上，
再增加一个骰子出现点数和为s的结果只有这6种情况。那么有
F(n, s) = F(n - 1, s - 1) + F(n - 1, s - 2) + F(n - 1, s - 3) 
        + F(n - 1, s - 4) + F(n - 1, s - 5) + F(n - 1, s - 6) 
③ 递归出口：s < 0 or s > 6n 时 F(n, s) == 0
 */
void PrintProbabilityII(int n) {
    int total = pow((double)g_max_val, n);
    for (int i = n; i <= g_max_val * n; i++) {
        cout << i << " " << (double)CountNumber(n, i) / total << endl;
    }
}

/**
 * 计算n个骰子某次投掷点数和为s的出现次数
 */
int CountNumber(int n, int s) {
    // n个骰子点数之和范围在n到6n之间，否则数据不合法
    if (s < n || s > n * g_max_val) return 0;
    // 当有一个骰子时，一次骰子点数为s(1 <= s <= 6)的次数当然是1
    if (n == 1)
        return 1;
    else
        return CountNumber(n - 1, s - 6) + CountNumber(n - 1, s - 5) +
               CountNumber(n - 1, s - 4) + CountNumber(n - 1, s - 3) +
               CountNumber(n - 1, s - 2) + CountNumber(n - 1, s - 1);
}

/**
方法三：动态规划（非递归实现）
dp(c,k) = dp(c-1,k-1) + dp(c-1,k-2) + dp(c-1,k-3)
        + dp(c-1,k-4) + dp(c-1,k-5) + dp(c-1,k-6)
        （注意当 k < 6时的处理越界问题）
出口：dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = 1
状态转移方程为：dp[c][k] = sum(dp[c-1][k-m]) (1 <= m <= 6 && m < k)
 */
void PrintProbabilityIII(int n) {
    if (n <= 0) return;
    // 结果可能性总数
    
    vector<int> vec_prob(n * 6 - n + 1, 0);

    // dp[c][k] c 个骰子朝上一面的点数之和为 k 的次数
    vector<vector<int>>dp(n + 1, vector<int>(6 * n + 1, 0));
    // 初始化 dp[1][1...6]
    for (int x = 1; x <= 6; x++) 
        dp[1][x] = 1;
    // 执行计算
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= 6 * n; j++) {
            int sum = 0;
            for (int m = 1; m < j && m <= 6; m++) {
                sum += dp[i - 1][j - m];
            }
            dp[i][j] = sum;
        }
    }
    // 统计结果，并输出
    int total = pow((double)6, n);
    for (int k = n; k <= 6 * n; k++) {
        double ratio = (double) dp[n][k] / total;
        cout << k << " " << ratio << " " << endl;

    }
}

int main() {
    int n = 4;
    PrintProbability(n);
    cout << endl;
    PrintProbabilityII(n);
    cout << endl;
    PrintProbabilityIII(n);
    return 0;
}