/**
 * Creation         :       2019.07.26 12:10
 * Last Reversion   :       2019.07.26 12:10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
multiply (构建乘积数组)
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素
B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(const vector<int>& A) {
    int length = A.size();
    if (length <= 0) return {};
    vector<int> B(length, 0);
    // 计算下三角
    B[0] = 1;
    for (int i = 1; i < length; i++) {
        B[i] = B[i - 1] * A[i - 1];
    }
    // 计算上三角
    int temp = 1;
    for (int j = length - 2; j >= 0; j--) {
        temp *= A[j + 1];
        B[j] *= temp;
    }
    return B;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> res = multiply(A);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}