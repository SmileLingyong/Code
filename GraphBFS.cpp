/**
 * Creation         :       2019.04.02 16:57
 * Last Reversion   :       2019.04:02 
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * BFS(广度优先搜索)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
const int MAXN = 50;
char str[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, ans, stx, sty, edx, edy;
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
struct node {
    int x, y;
    node() {}
    node(int _x, int _y) : x(_x), y(_y) {}
};

void BFS(int x, int y) {
    vis[x][y] = 1;
    ans++;
    node e1 = node(x, y);
    queue<node> que;
    que.push(e1);
    while (que.size()) {
        node e2 = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int dx = e2.x + d[i][0];
            int dy = e2.y + d[i][1];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy] && str[dx][dy] != '#') {
                ans++;
                vis[dx][dy] = 1;
                que.push(node(dx, dy));
            }
        }
    }
}

int main() {
    while (~scanf("%d %d", &m, &n) && (n | m)) {
        memset(str, 0, sizeof(str));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) 
            scanf("%s", str[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (str[i][j] == '@') {
                    stx = i;
                    sty = j;
                    break;
                }
            }
        ans = 0;
        BFS(stx, sty);
        printf("%d\n", ans);
    }
    return 0;
}