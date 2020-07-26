/**
 * Creation         :       2019.07.17 15:01
 * Last Reversion   :       2019.07.17 15:01
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
solveSudoku（解数独）
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。
一个数独。

答案被标成红色。

Note:

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 判断该位置是否可以放置该ch数
 */ 
bool is_valid(vector<vector<char>> &board, int row, int col, int ch) {
    for (int i = 0; i < board.size(); i++) {
        int x = (row / 3 * 3 + i / 3);
        int y = (col / 3 * 3 + i % 3);
        if (board[i][col] == ch || board[row][i] == ch || board[x][y] == ch)
            return false;
    }
    return true;
}

/**
 * DFS
 */ 
bool DFS(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                for (int ch = '1'; ch <= '9'; ch++) {
                    if (is_valid(board, i, j, ch)) {
                        board[i][j] = ch;
                        if (DFS(board)) 
                            return true;
                        else 
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

/**
 * 方法一：DFS 按照8皇后的思想，递归与回溯
 */ 
void solveSudoku(vector<vector<char>>& board) {
    if (board.size() == 0)
        return;
    DFS(board);
}


int main() {
    vector<vector<char>> board = 
    {{'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}