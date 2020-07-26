/**
 * Creation         :       2019.08.18 20:38
 * Last Reversion   :       2019.08.18 20:50
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
MinDistance(编辑距离)
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

示例 1:
输入: word1 = "horse", word2 = "ros"
输出: 3

解释:
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2:
输入: word1 = "intention", word2 = "execution"
输出: 5

解释:
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <vector>
using namespace std;

/*
思路：动态规划
dp[i][j]代表 word1到 i 位置转换成word2到 j 位置需要最少步数，所以：
当 word1[i] == word2[j]，dp[i][j] = dp[i-1][j-1]
当 word1[i] != word2[j], dp[i][j] = min(dp]i-1][j-1], dp[i-1][j], dp[i][j-1])
其中，dp[i-1][j-1] 表示替换操作，dp[i-1][j]
表示删除操作，dp[i][j-1]表示插入操作。 注意，针对第一行，第一列要单独考虑，引入
'' 下图所示：
              ''   r   0   s
        ''    0    1   2   3
        h     1
        o     2
        r     3
        s     4
        e     5
第一行，是word1 为空变成 word2 最少步数，就是插入操作
第一列，是word2 为空，需要最少的步数，就是删除操作
*/
int minDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int j = 1; j < n2 + 1; j++) {
        dp[0][j] = dp[0][j - 1] + 1;
    }
    for (int i = 1; i < n1 + 1; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int i = 1; i < n1 + 1; i++) {
        for (int j = 1; j < n2 + 1; j++) {
            if (word1[i-1] == word2[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
        }
    }
    return dp[n1][n2];
}

int main() {
    string word1, word2;
    cin >> word1;
    cin >> word2;
    cout << minDistance(word1, word2) << endl;
    return 0;
}