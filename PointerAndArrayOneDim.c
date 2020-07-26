/**
 * Creation         :       2019.03.05 10:31
 * Last Reversion   :       2019.03.05 10:55
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 一维指针和一维数组 (Pointer and array) P292 
 *      输入一个含5个数的一维数组，然后输出这个一维数组的元素值。
 * 共可以有4种方式：
 *      ①被调函数的形参声明为 数组类型，下标法 访问数组元素
 *      ②被调函数的形参声明为 指针类型，指针法 访问数组元素
 *      ③被调函数的形参声明为 数组类型，指针法 访问数组元素
 *      ④被调函数的形参声明为 指针类型，下标法 访问数组元素
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#define N 5

/* ①被调函数的形参声明为 数组类型，下标法 访问数组元素 */
void InputArraySub(int a[], int n) {        // 注意剑指offer P39有个易错考点
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}   

void OutputArraySub(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* ②被调函数的形参声明为 指针类型，指针法 访问数组元素 */
void InputPointerPoint(int *p, int n) {
    for(int i = 0; i < n; i++)
        scanf("%d", p++);
}

void OutputPointerPoint(int *p, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", *p++);
    printf("\n");    
}

/* ③被调函数的形参声明为 数组类型，指针法 访问数组元素 */
void InputArrayPoint(int a[], int n) {
    for(int i = 0; i < n; i++)
        scanf("%d", a++);
}

void OutputArrayPoint(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", *a++);
    printf("\n");
}

/* ④被调函数的形参声明为 指针类型，下标法 访问数组元素 */
void InputPointerSub(int *p, int n) {
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);
}

void OutputPointerSub(int *p, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");    
}

int main() {
    int a[N];
    printf("Please input five int number: \n");
    /* ①被调函数的形参声明为 数组类型，下标法 访问数组元素 */
    // InputArraySub(a, N);
    // OutputArraySub(a, N);

    /* ②被调函数的形参声明为 指针类型，指针法 访问数组元素 */
    // InputPointerPoint(a, N);
    // OutputPointerPoint(a, N);

    /* ③被调函数的形参声明为 数组类型，指针法 访问数组元素 */
    // InputArrayPoint(a, N);
    // OutputArrayPoint(a, N);

    /* ④被调函数的形参声明为 指针类型，下标法 访问数组元素 */
    InputPointerSub(a, N);
    OutputPointerSub(a, N);

    return 0;
}

