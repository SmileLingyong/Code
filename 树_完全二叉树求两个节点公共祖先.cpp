/**
 * Creation         :       2019.03.18 19:56
 * Last Reversion   :       2019.03.18 20:15
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 完全二叉树求两节点公共祖先 (BinaryTreeComAncestor) P天勤 150
 * 题目描述：
 *      已知一个完全二叉树按顺序存储结构存储在 tree[]中，假设二叉树节点值类型为char型，节点个数为n。
 * 设计一个算法，求出离下标分别为 i 和 j 的两个节点最近的公共祖先节点的值。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>

/**
 * 返回公共祖先节点的值
 *    思想： 用两个指针 p, q 分别之心啊下标为 i, j 的两个节点（p, q 保存了两个节点再数组中的下标），
 * 然后使 p, q 沿着从所在节点到树根的路径往上移动。
 * 移动规则：
 *    (1) 若 p > q, 则 p 向上移动，q 不动
 *    (2) 若 q > p, 则 q 向上移动, p 不动
 *    (3) 当 p, q 第一次相遇时，p, q 所之心啊的节点即为距离原节点最近的公共祖先节点（自己画图易理解）
 */ 
char Ancestor(char tree[], int i, int j) {
    int p = i, q = j;
    while (p != q) {
        if (p > q)
            p /= 2;
        else 
            q /= 2;
    }
    return tree[p-1];
}


int main() {
    char tree[] = {'1', '2', '3', '4', '5', '6'};
    int i = 2, j = 6;   // 注意这里的下标     
    printf("The first common ancestor is %c\n", Ancestor(tree, i, j));
    return 0;
}
