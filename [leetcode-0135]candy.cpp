/**
 * Creation         :       2019.03.16 14:37
 * Last Reversion   :       2019.03.16 15:00
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 分发糖果 (candy)
 *      老师想给孩子们分发糖果，有 N
 * 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 *      （1）每个孩子至少分配到 1 个糖果。
 *      （2）相邻的孩子中，评分高的孩子必须获得更多的糖果。
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 * 示例 1:
 *      输入: [1,0,2]
 *      输出: 5
 * 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
 * 示例 2:
 *      输入: [1,2,2]
 *      输出: 4
 * 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
 * 第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define N 1000

/**
 * (1)从左往右遍历一遍，让右边比左边分数高的candy也高
 * (2)从右往左遍历一遍，保证左边比右边高的candy也高
 */
int candy(vector<int>& ratings) {
    if (ratings.size() == 1) return 1;
    int i, j, len, sum = 0;
    len = ratings.size();
    vector<int> gift(len, 1);
    // 从左往右遍历
    for (i = 1; i < len; i++) {
        if (ratings[i] > ratings[i-1])
            gift[i] = gift[i-1] + 1;
    }
    // 从右往左遍历
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