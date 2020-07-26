/**
 * Creation         :       2019.03.08 23:26
 * Last Reversion   :       2019.03.08 23:40
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * ArrayFind(二维数组中的查找) 使用vector
 * 题目描述
 *    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右
 * 递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，
 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 例如：
 *      1   2   8   9
 *      2   4   9   12
 *      4   7   10  13
 *      6   8   11  15
 * 如果查找数字 7，则返回true
 * 如果查找数字 5，则放回false
 * Reference: 
 *    - https://blog.csdn.net/a819825294/article/details/52088732
 *    - https://blog.csdn.net/duan19920101/article/details/50617190
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
using namespace std;

#define N 100

/**
 * 使用下标法访问vector二维数组
 */ 
bool FindSub(int target, vector<vector<int> > array) {
    int i, j;
    for (i = 0; i < array.size(); i++) 
        for (j = 0; j < array[0].size(); j++)
            if(array[i][j] == target)
                return true;
    return false;
}

/**
 * 使用迭代器方位vector二维数组
 */ 
bool FindIterator(int target, vector<vector<int> > array) {
    vector<int>::iterator it;
    vector<vector<int> >::iterator iter;
    for (iter = array.begin(); iter != array.end(); iter++) 
        for (it = (*iter).begin(); it != (*iter).end(); it++)
            if (*it == target)
                return true;
    return false;
}

/**
 * 方法三： 矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
 * 因此从左下角开始查找，当要查找数字比左下角数字大时。右移要
 * 查找数字比左下角数字小时，上移
 * 时间复杂度： O(n^2)
 */ 
bool FindSubII(int target, vector<vector<int> > array) {
    int row = array.size();
    int col = array[0].size();
    for (int i = row - 1, j = 0; i >= 0 && j < col; ) {
        if (target == array[i][j]) 
            return true;
        if (target < array[i][j]) 
            i--;
        else if (target > array[i][j]) 
            j++;
    }
    return false;
}

int main() {
    int row, col, target, i, j;
    printf("Please input the array row num: ");
    scanf("%d", &row);
    printf("Please input the array col num: ");
    scanf("%d", &col);

    vector<vector<int> > array(row); // 由vector实现的二维数组，可以通过resize()的形式改变行、列值
    for (i = 0; i < row; i++)
        array[i].resize(col);       // 得到一个row行col列的数组

    printf("Please input the array: \n");
    for (i = 0; i < array.size(); i++)
        for (j = 0; j < array[0].size(); j++) 
            scanf("%d", &array[i][j]);  // 利用下标访问

    printf("Please input the target number: \n");
    scanf("%d", &target);

    if (FindSubII(target, array))
        printf("true.\n");
    else
        printf("false.\n");

    return 0;
}