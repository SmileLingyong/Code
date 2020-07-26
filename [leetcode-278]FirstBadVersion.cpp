/**
 * Creation         :       2019.06.30 16:09
 * Last Reversion   :       2019.06.30 16:16
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * firstBadVersion(第一个错误的版本) 
 * 题目描述
你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。
由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。假设你有 n 个版本
[1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。
实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例:
给定 n = 5，并且 version = 4 是第一个错误的版本。
调用 isBadVersion(3) -> false
调用 isBadVersion(5) -> true
调用 isBadVersion(4) -> true
所以，4 是第一个错误的版本。 
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;

/**
 * 这里是为了不让文件报错，然后写的一个假的函数
 */ 
bool isBadVersion(int n) {
    return false;
}

/**
 * 方法一：二分查找
 */ 
int firstBadVersion(int n) {
    long long l = 1, r = n, mid;
    while (l != r) {
        mid = (l + r) / 2;
        if (!isBadVersion(mid)) {   // 是好的，则在后面继续查找
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}