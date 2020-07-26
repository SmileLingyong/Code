/**
 * Creation         :       2019.07.19 12:20
 * Last Reversion   :       2019.07.19 12:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
InversePairs (数组中的逆序对)
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
即输出P%1000000007

输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5

示例1：
输入
1,2,3,4,5,6,7,0
输出
7
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 归并排序思想
 */ 
int InverseParisCore(vector<int> &data, int l, int r, vector<int> &copy) {
	
	if (l == r) return 0;
	int mid = (l + r) / 2;
	long long left_count = InverseParisCore(data, l, mid, copy);
	long long right_count = InverseParisCore(data, mid + 1, r, copy);
	int count = 0;
	int i = mid, j = r;
	int idx = r;
	while (i >= l && j > mid) {
		if (data[i] > data[j]) {
			count += j - mid;
			copy[idx--] = data[i--];
			if (count >= 1000000007) {
				count %= 1000000007;
			}
		} else {
			copy[idx--] = data[j--];
		}
	}
	while (i >= l) {
		copy[idx--] = data[i--];
	}
	while (j > mid) {
		copy[idx--] = data[j--];
	}
	for (int k = l; k <= r; k++) {
		data[k] = copy[k];
	}
	return (left_count + right_count + count) % 1000000007;
}

int InversePairs(vector<int> data) {
	int length = data.size();
    if (length <= 0) return 0;
	vector<int> copy(length, 0);
	return InverseParisCore(data, 0, length - 1, copy);
}

int main() {
	vector<int> data = {1, 2, 3, 4, 5, 6, 7, 0, 2};
	cout << InversePairs(data) << endl;
    return 0;
}