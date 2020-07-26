/**
 * Creation         :       2019.03.31 15:06
 * Last Reversion   :       2019.04:01 14:29
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 题目描述：
 *    超级斐波拉契数列：求斐波拉契数列第一亿项的值（取模）
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 2, M = 2, P = 2;  //矩阵1: N*P； 矩阵2: P*M
const int MOD = 100000007;
typedef struct Mat {
    long long data[N][N];
} Mat;

Mat A = {1, 1, 1, 0};
Mat I = {1, 0, 0, 1};   // 单位阵

/**
 * 矩阵乘法定义
 */
Mat Multi(Mat a, Mat b) {
    Mat res;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            res.data[i][j] = 0;  
            for (int k = 0; k < P; k++)
                res.data[i][j] += (a.data[i][k] * b.data[k][j] % MOD);  //取模
            res.data[i][j] %= MOD;                                      //取模
        }
    return res;
}

/**
 * 矩阵快速幂
 */ 
Mat PowMatrix(Mat a, int n) {
    Mat ans = I, base = a;
    while (n) {
        if (n & 1) 
            ans = Multi(ans, base);
        base = Multi(base, base);
        n >>= 1;                //  n /= 2;
    }
    return ans;
}

int main() {
    int n;
    while (scanf("%d", &n)) {
        Mat res = PowMatrix(A, n - 1); 
        printf("%lld\n", res.data[0][0]);
    }
    return 0;
}