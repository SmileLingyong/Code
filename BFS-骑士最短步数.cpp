/**
 * Creation         :       2019.04.04 21:12
 * Last Reversion   :       2019.04.04 21:25
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * BFSShortestPath(骑士最短路径)
 * 问题描述：
 *    在一个8*8的矩形格子中找起始位置 start(x, y) 到 终点位置 end(x, y) 的最短路径。
 * 输出最短的路径长度，并输出路径顺序点。
 * 思路：
 *    使用BFS思想(类似于层次遍历)，单源最短路径。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
#define maxSize 100

typedef struct Point {
    int x;
    int y;
} Point;

int direction[][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                      {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};  // 定义马日跳

int BFS(Point start, Point end) {
    int step[9][9] = {0};                           // 存放起始点到达8x8网格每一点时刻走的步数
    Point cur, next;
    Point que[maxSize];
    int front, rear;
    front = rear = 0;
    rear = (rear + 1) % maxSize;    
    que[rear] = start;                              // 起始点入队
    while (rear != front) {                         // 当队列不为空
        front = (front + 1) % maxSize;              // 队首元素出队
        cur = que[front];
        if (cur.x == end.x && cur.y == end.y) {     // 跳到终点时，返回当前走的路径长度，即为最短路径
            return step[cur.x][cur.y];
        }
        for (int i = 0; i < 8; i++) {               // 没跳到终点，继续遍历当前位置的下一跳
            next.x = cur.x + direction[i][0];
            next.y = cur.y + direction[i][1];
            if (next.x < 1 || next.x > 8 || next.y < 1 || next.y > 8) continue;
            if (step[next.x][next.y] == 0) {        // 若当前点未被访问，则将其加入队列
                step[next.x][next.y] = step[cur.x][cur.y] + 1;
                rear = (rear + 1) % maxSize;
                que[rear] = next;
            }
        }
    }
}

int main() {
    Point start, end;
    scanf("%d %d", &start.x, &start.y);
    scanf("%d %d", &end.x, &end.y);
    printf("The min moves is %d", BFS(start, end));
    return 0;
}
