/**
 * Creation         :       2019.03.24 11:12
 * Last Reversion   :       2019.03.24 11:54
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * MinNumberInRotateArray(旋转数组的最小数字)
 * 题目描述
 *    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个
 * 递增排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}
 * 的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/**
使用二分查找的思想：
    mid = low + (high - low) / 2
需要考虑三种情况：
(1)array[mid] > array[high]:
    出现这种情况的array类似[3,4,5,6,0,1,2]，此时最小数字一定在mid的右边。
        low = mid + 1
(2)array[mid] == array[high]:
    出现这种情况的array类似 [1,0,1,1,1] 或者[1,1,1,0,1]，此时最小数字不好判断在mid左边，还是右边,这时只好一个一个试, high--,因为是升序的
        high = high - 1
(3)array[mid] < array[high]:
    出现这种情况的array类似[2,2,3,4,5,6,6],此时最小数字一定就是array[mid]或者在mid的左边。因为右边必然都是递增的。
        high = mid
    注意这里有个坑：如果待查询的范围最后只剩两个数，那么mid 一定会指向下标靠前的数字
        比如 array = [4,6]
        array[low] = 4; array[mid] = 4; array[high] = 6;
    如果high = mid - 1，就会产生错误， 因此high = mid
    但情形(1)中low = mid + 1就不会错误
 */ 
int MinNumberInRotateArray(vector<int> rotateArray) {
    int low = 0, high = rotateArray.size() - 1, mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (rotateArray[mid] > rotateArray[high])
            low = mid + 1;
        else if (rotateArray[mid] == rotateArray[high])
            high--;
        else
            high = mid;
    }
    return rotateArray[low];
}

/**
 * 思想：直接遍历
 * 因为是将生序数组的前面一段放到了后面一段，所以只要找到数组升序段末尾即可，
 * （1）如果末尾不是最后一个元素，则下一个元素则是最小的元素；
 * （2）如果末尾是最后一个元素，则说明该数组已经是生序的，返回第一个元素即可。
 */ 
int MinNumberInRotateArrayLLY(vector<int> rotateArray) {
    if (rotateArray.empty())
        return 0;
    for (int i = 0; i < rotateArray.size() - 1; i++) {
        if (rotateArray[i + 1] < rotateArray[i]) {
            return rotateArray[i + 1];
        }
    }
    return rotateArray[0];
}

int main() {
    int n, x, i, res = 0;
    vector<int> a;
    printf("Please intpu a int number n: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        a.push_back(x);
    }
    res = MinNumberInRotateArrayLLY(a);
    if (res)
        printf("The min num is %d\n", res);
    else
        printf("The intpu array is empty.\n");
    return 0;
}