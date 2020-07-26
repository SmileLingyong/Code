/**
 * Creation         :       2019.04.02 16:57
 * Last Reversion   :       2019.04:02 
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * DFS(深度优先搜索)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
char str[MAXN][MAXN];
bool vis[MAXN][MAXN];
int d[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n, m, ans;
int stx, sty, edx, edy;

void DFS(int x, int y) {
    vis[x][y] = 1;
    ans++;
    for (int i = 0; i < 4; i++) {
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        if (dx >= 0 && dy >= 0 && dx < n && dy < m && !vis[dx][dy] && str[dx][dy] != '#') { // 判断条件不能搞错
            vis[dx][dy] = 1;
            DFS(dx, dy);
        }
    }
}

int main() {
    while (~scanf("%d %d", &m, &n) && (n | m)) {
        memset(str, 0, sizeof(str));   // 不初始化 Wa
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) scanf("%s", str[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (str[i][j] == '@')  // 找到起点
                {
                    stx = i;
                    sty = j;
                    break;
                }
            }
        ans = 0;
        DFS(stx, sty);                  // 从起点开始搜索
        printf("%d\n", ans);
    }
    return 0;
}