/**
 * Creation         :       2019.03.08 09:54
 * Last Reversion   :       2019.03.08 10:30
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 常用的排序算法
 *      内部排序
 *          1.插入排序                    平均复杂度        最好          最坏
 *              （1）直接插入排序 （稳定）   【O(n^2)        O(n)        O(n^2)】
 *              （2）希尔排序    （不稳定） 【O(n^{3/2})     O(n)        O(n^2)】
 *          2.交换排序
 *              （1）冒泡排序     （稳定）  【O(n^2)         O(n)        O(n^2)】
 *              （2）快速排序    （不稳定） 【O(nlongn)    O(nlongn)     O(n^2)】
 *          3.选择排序
 *              （1）简单选择排序 （不稳定） 【O(n^2)        O(n^2)       O(n^2)】
 *              （2）堆排序      （不稳定） 【O(nlongn)    O(nlongn)     O(nlongn)】
 *          4.归并排序           （稳定）  【O(nlongn)    O(nlongn)     O(nlongn)】
 *          5.基数排序           （稳定）  【O(n)            O(n)        O(n)】
 *      外部排序
 *          6.多路归并排序
 * -----------------------------------------------------------------
 * Reference: https://blog.csdn.net/Koala_Tree/article/details/79958965
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    直接插入排序
(1) 从第一个元素开始，该元素可以认为已经被排序；
(2) 取出下一个元素，在已经排序的元素序列中从后向前扫描；
(3) 如果该元素（已排序）大于新元素，将该元素移到下一位置；
(4) 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
(5) 将新元素插入到该位置后；
(6) 重复步骤2~5。
 */ 
void Insert(int a[], int n) {
    int i, j, cur;
    for (i = 1; i < n; i++) {
        cur = a[i];
        for (j = i; j > 0 && a[j - 1] > cur; j--)
            a[j] = a[j - 1];
        a[j] = cur;
    }
}

/**
   希尔排序
先将整个待排元素序列分割成若干子序列（由相隔某个“增量”的元素组成的）分别进行
直接插入排序，然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时，
再对全体元素进行一次直接插入排序（增量为1）。其时间复杂度为O(n^3/2),要好于直接插入排序的O(n^2)
 */ 
void ShellInsert(int a[], int n) {
    int i, j, step, cur;
    for (step = n / 2; step > 0; step /= 2) {  
        for (i = step; i < n; i++) {
            cur = a[i];
            for (j = i; j >= step; j -= step) {  // 这里j要大于等于step，因为step最小为1，就和上面的直接插入j>0是等价的了
                if (a[j - step] > cur)
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = cur;
        }
    }
}



/**
 * @brief ExchangeSort:   基本交换排序：[升序为例] 第一趟排序，将第一个数分别与后面所有的数进行比较，若后面的数比较小，
 *   [O(n^2) 稳定的]    则交换后面的这个数和第一个数的位置，继续将第一个位置的数，与后面的数进行比较，这样，第一轮比较完，
 *                     最小的数就放在了第一数的位置。然后第二轮比较，将第二个数，与后面的数进行比较，以此类推。
 * @param int a[]: int类型数组做为形参
 * @param int n:   数组的长度
 */ 
void ExchangeSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

/**
 * @brief BubbleSort:    冒泡排序: [升序为例] 第一趟排序，从前往后，两两比较相邻元素的值，若为逆序(即, a[j] > a[j+1])，
 *   [O(n^2) 稳定的]   则交换他们，直到序列比较完，最后该趟最大的元素排列到序列最后(元素最大的向气泡一样逐渐上浮)。
 *                    下一趟排序时，前一趟确定的最大的数不再参与比较，待排序列减少一个元素，每趟排序把序列中最大的
 *                    元素放到该趟序列的最后。
 * @param int a[]: int类型数组做为形参
 * @param int n:   数组的长度
 */ 
void BubbleSort(int a[], int n) {
    int i, j, temp, flag;
    for (i = n - 1; i >= 0; i--) {
        flag = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            return;
        }
    }
}


/**
 * @brief QuickSort:      快速排序： 基本思想是采用分治的思想。再待排序列表 a[l...r] 中去第一个元素做为基准key，
 * [O(nlogn) 不稳定的]  通过一趟排序将待排序表划分为独立的两个部分 a[l...k-1] 和 a[k+1...r]，使得a[l...k-1]中所有的元素小于key，
 *                    a[k+1...r]中所有的元素大于或等于key，则key放在了其最终位置 a[k]上，以上为一趟排序。然后分别递归的对两个子表
 *                    重复上述过程，直至每部分只有一个元素或为空为止，即所有元素放在了其最终的位置。
 * @param int a[]: int类型数组做为形参
 * @param int l:   数组a左下标
 * @param int r:   数组a右下标
 */ 
void QuickSort(int a[], int l, int r) {
    int key;
    int i = l, j = r;
    if (l < r) {
        key = a[l];
        while(i < j){
            while(i < j && a[j] > key) j--;
            if (i < j) {
                a[i] = a[j];
                i++;
            }
            while(i < j && a[i] < key)  i++;
            if (i < j) {
                a[j] = a[i];
                j--;
            }
        }
        a[i] = key;
        QuickSort(a, l, i - 1);
        QuickSort(a, i + 1, r);
    }
}


/**
 * @brief SelectSort:     简单选择排序：[升序为例] 第一趟排序，将第一个数分别与后面所有的数进行比较，若后面的数比较小，
 *   [O(n^2) 不稳定的]   则交换后面的这个数和第一个数的位置，继续将第一个位置的数，与后面的数进行比较，这样，第一轮比较完，
 *                     最小的数就放在了第一数的位置。然后第二轮比较，将第二个数，与后面的数进行比较，以此类推。
 * @param int a[]: int类型数组做为形参
 * @param int n: 数组的长度
 */ 
void SelectSort(int a[], int n) {
    int i, j, temp, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

/**
 * 将两个有序数列a[l...mid] 和 a[mid+1...last] 合并
 */ 
void mergeArray(int a[], int l, int mid, int r, int temp[]) {
    int i = l, j = mid + 1;
    int m = mid, n = r;
    int k = 0;
    while (i <= m && j <= n) {      // 谁小就先取谁
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= m)                  // 若a[l...mid]不为空，则将其都加入temp[]中
        temp[k++] = a[i++];
    while (j <= n)                  // 若a[mid+1...last]不为空，则将其都加入temp[]中
        temp[k++] = a[j++];
    for (i = 0; i < k; i++)         // 将temp数组覆盖原数组a
        a[l + i] = temp[i];
}

/**
 * 分而治之，不断将数组拆分为两个个子数组，直到子数组元素为1个，然后再开始合并
 */ 
void mergeSort(int a[], int l, int r, int temp[]) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid, temp);         // 左边有序
        mergeSort(a, mid + 1, r, temp);     // 右边有序
        mergeArray(a, l, mid, r, temp);     // 将两个有序数列合并
    }
}

/**
 * 归并排序
 * [O(nlogn)]
 * Reference： 
 *  - [归并排序图解](https://www.cnblogs.com/chengxiao/p/6194356.html)
 *  - [代码实现](https://blog.csdn.net/morewindows/article/details/6678165)
 */ 
void MergeSort(int a[], int n) {
    int *p = (int*)malloc(sizeof(int) * n);
    if (p == NULL)
        printf("malloc error!\n");
    mergeSort(a, 0, n - 1, p);
    free(p);
}

// void MergeSort(int a[], int n) {
//     int p[n];
//     mergeSort(a, 0, n - 1, p);
// }


/**
 * @brief HeapSort:        堆排序：
 *  [O(nlogn) 不稳定的]  
 * @param int a[]: int类型数组做为形参
 * @param int n: 数组的长度
 * @注意：其中初始化建堆的时间复杂度为： O(n)，反复重建调整堆的时间复杂度为: O(logn) 
 * 最终的时间复杂度为： 1次建堆 + n次堆调整 = O(n + nlogn) = O(nlogn)   参考最后一个引用
 * Reference:  （自己一定要debug一遍才行，好好把该弄懂的都好好弄懂才行！）
 *  - https://www.cnblogs.com/chengxiao/p/6129630.html
 *  - https://blog.csdn.net/morewindows/article/details/6709644
 *  - https://elloop.github.io/c++/2016-11-29/learning-using-stl-72-make-heap
 *  - https://www.zhihu.com/question/20729324
 * 思想：
 *     将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。将其与末尾元素进行交换，
 * 此时末尾就为最大值。然后将剩余n-1个元素重新构造成一个堆，这样会得到n个元素的次小值。如此反复执行，
 * 便能得到一个有序序列了。
 */ 
void AdjustHeap(int a[], int i, int len) {
    int temp = a[i];
    int j = 2*i+1;              // a[j] 是 a[i] 的左孩子节点
    for ( ; j < len; j = j*2+1) {           // 从i结点的左子结点开始，也就是 2i+1 处开始
        if (j+1 < len && a[j] < a[j+1]) {   // 如果左子结点小于右子结点，j 指向右子结点
            j++;
        }
        if (a[j] > temp) {      // 如果子节点大于父节点，将子节点值赋值给父节点（不用进行交换，因为每次比较都是用的temp比较的）
            a[i] = a[j];
            i = j;
        } else {
            break;
        }
    }
    a[i] = temp;                // 将被调整节点值，放到最终位置
}


void HeapSort(int a[], int len) {
    // 构建大顶堆
    for (int i = len/2-1; i >= 0; i--) {
        // 从第一个非叶子节点，按照：从下至上，从右至左调整结构
        AdjustHeap(a, i, len);
    }
    // 进行 n - 1 次循环完成堆排序，调整堆结构+交换堆顶元素与末尾元素
    for (int j = len-1; j > 0; j--) {
        int temp = a[0];    // 将堆顶元素与末尾元素进行交换
        a[0] = a[j];
        a[j] = temp;
        AdjustHeap(a, 0, j);
    }
}

/**
 * @brief OutputArray: 打印输出数组
 * @param int a[]: int类型数组做为形参
 * @param int n: 数组的长度
 */ 
void OutputArray(int a[], int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ", a[i]);
    printf("\n");
}

/**
 * @brief InitArray: 将数组b中size大小的内容拷贝到a中
 * @param int a[]: 待初始化数组
 * @param int b[]: 备份的数组
 * @param int size: 备份的数组大小
 */ 
void InitArray(int a[], int b[], int size) {
    memcpy(a, b, size);  // 注意，这里不能写成 memcpy(b, a, sizeof(a));
                         // 因为此时的形参a是一个int类型的指针变量，sizeof(a)则为4个字节大小
}

int main() {
    int a[] = {5, 3, 2, 3, 1, 6, 8, 4, 0, 9};
    int *b = NULL, size, len;

    size = sizeof(a);
    len = sizeof(a) / sizeof(int);
    b = (int *)malloc(sizeof(a));
    memcpy(b, a, size);  // 拷贝a数组至b数组

    printf("Ori array is: \n");
    OutputArray(a, len);

    /* 插入排序 */
    InitArray(a, b, size);  // 将b数组拷贝回a数组，达到初始化目的
    Insert(a, len);
    printf("Insert sort array is: \n");
    OutputArray(a, len);

    /* 希尔排序 */
    InitArray(a, b, size);  // 将b数组拷贝回a数组，达到初始化目的
    ShellInsert(a, len);
    printf("Shell sort array is: \n");
    OutputArray(a, len);


    /* 交换排序 */
    InitArray(a, b, size);  
    ExchangeSort(a, len);
    printf("Exchange sort array is: \n");
    OutputArray(a, len);

    /* 冒泡排序 */
    BubbleSort(a, len);
    printf("Bubble sort array is: \n");
    OutputArray(a, len);

    /* 快速排序 */
    InitArray(a, b, size);
    QuickSort(a, 0, len - 1);
    printf("Quick sort array is: \n");
    OutputArray(a, len);

    /* 简单选择排序 */
    InitArray(a, b, size);
    SelectSort(a, len);
    printf("Select sort array is: \n");
    OutputArray(a, len);

    /* 归并排序 */
    InitArray(a, b, size);
    MergeSort(a, len);
    printf("Merge sort array is: \n");
    OutputArray(a, len);

    /* 堆排序 */
    InitArray(a, b, size);
    HeapSort(a, len);
    printf("Select sort array is: \n");
    OutputArray(a, len);

    free(b);
    return 0;
}