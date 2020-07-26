/**
 * Creation         :       2019.04.04 14:50
 * Last Reversion   :       2019.03.04 15:22
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * EightQueenII(八皇后问题II，不定义全局变量实现)
 * 问题描述：
 *    即在一个8*8的矩形格子中排放8个皇后,要满足的条件包括: 任意两个皇后都不能在同一行/列/对角线(斜率等于1/-1).
 * 要求编程给出所有第一行第一列有皇后的解 (注：解的输出用8个数字表示,如：基本解{1,5,8,6,3,7,2,4},其中'1'表示
 * 第一行第一列即(1,1)处有皇后, 后同)
 * 
 * 思路：
 *    跟穷举查不多，我们依次在每一行放一个皇后，而一行有八列，所以我们在放置一个皇后时，就要马上判断皇后放置的
 * 列是否符合条件，如果符合，我们就放置下一个皇后，如果不符合，我们就尝试着将皇后放置在下一列，接着像刚才一样
 * 判断皇后放置的列是否合法...如此循环，直到最后一列为止。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
#include <stdlib.h>
#define N 8

/**
 * 打印八皇后图表形式 
 */ 
void Paint(int *queen) {
	for (int i = 0; i < N; i++) {
		for (int j=0; j < N; j++) {
			if(queen[i] == j)
				printf("■ ");       // 输出皇后 
			else
				printf("□ ");
		}
		printf("\n");
	}
	printf("\n");
} 

/**
 * 输出所有皇后坐标
 */ 
void PrintfPutQueen(int *queen) {	            
	for (int i = 0; i < N; i++) {
		printf("(%d,%d) ", i, queen[i]);
	} 
	printf("\n");
}

int CanPut(int row, int *queen) {
	for (int i = 0; i < row; i++) { // 将第 row 行皇后与前面所有行的皇后进行比较
		if (queen[row] == queen[i] || (abs(queen[row] - queen[i]) == (row - i)))    // 检查横排和对角线上是否可以放置皇后 
			return 0;               // 不能放置皇后 
	}
	return 1;                       // 可以放置皇后 
}

/**
 * 放置皇后
 */  
int PutQueen(int row, int *queen) {
	int sum = 0;
	if (row >= N) {				    // 说明皇后都已经放好了
        Paint(queen);
		return 1;
	} else {
		for (int i = 0; i < N; i++) {               // 总共有N列，一列一列的试探放置皇后 
			queen[row] = i;		                    // 将第row行皇后放置在第i列
			if (CanPut(row, queen)) {               // 判断是否可以放置该皇后 
				sum += PutQueen(row + 1, queen);    // 放下一个行皇后 
			}
		}
	}
	return sum;
}

int main() {
	int queen[N] = {0}, sum = 0; 	// 数组queen[N]的下标表示皇后所在的行，queen[N]其值表示皇后所在的列
	sum = PutQueen(0, queen);
	printf("Sum = %d\n", sum);
	return 0;
}