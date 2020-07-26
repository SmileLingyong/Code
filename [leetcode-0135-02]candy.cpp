/**
 * Creation         :       2019.03.16 14:37
 * Last Reversion   :       2019.03.16 14:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 分发糖果[变种] (candy)
 *      老师想给孩子们分发糖果，有 N个孩子围城一圈，老师会根据每个孩子的表现，预先给他们评分。
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 *      （1）每个孩子至少分配到 1 个糖果。
 *      （2）相邻的孩子中，评分高的孩子必须获得更多的糖果。
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 * 示例 1:
 *      输入: 
 *           2
 *           2
 *           1 2
 *           4
 *           1 2 3 3
 *      输出: 
 *           3
 *           8
 * 思想：有环的话，处理起来就麻烦点，不能想当然，要考虑边界条件。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define N 1000

/**
 * 方法一：补全首尾成环
 * 如输入 1 4 3 2 0
 * 则，通过补全处理 [0] 1 4 3 2 0 [1]
 * (1)从左往右遍历一遍，让右边比左边分数高的candy也高
 * (2)从右往左遍历一遍，保证左边比右边高的candy也高
 * （注意首尾的处理！）
 */
int candy(vector<int>& ratings) {
    if (ratings.size() == 1) return 1;
    int i, j, len, sum = 0;
    len = ratings.size();
    vector<int> gift(len, 1);
    // 从左往右遍历
    // 处理第一个人，将其与最后一个人比较
    if (ratings[0] > ratings[len-1])
        gift[0] = gift[len-1] + 1;
    for (i = 1; i < len; i++) {
        if (ratings[i] > ratings[i-1])
            gift[i] = gift[i-1] + 1;
    }

    // 从右往左遍历
    // 处理最后一个人，将其与第一个人比较
    if (ratings[len-1] > ratings[0] && gift[len-1] <= gift[0])
        gift[len-1] = gift[0]+1;
    for (i = len - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1] && gift[i] <= gift[i+1])
            gift[i] = gift[i+1] + 1;
    }
    for (i = 0; i < len; i++) 
        sum += gift[i];
    return sum;
}

int main() {
    int x, m, n, i, j;
    vector<int> ratings;
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &n);
        for (j = 0; j < n; j++) {
            scanf("%d", &x);
            ratings.push_back(x);
        }
        printf("%d\n", candy(ratings));
    }
    return 0;
}