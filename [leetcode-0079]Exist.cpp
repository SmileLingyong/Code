/**
 * Creation         :       2019.06.23 11:25
 * Last Reversion   :       2019.06.23 11:36
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * exist(单词搜索) 
给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
示例:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

思路：
   相当于与剑指offer-12 矩阵路径
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

bool existDFS(vector<vector<char>> &board, string word, int rows, int cols, int row, int col, int path_len, vector<vector<int>> &visited) {
    if (word[path_len] == '\0') {
        return true;
    }
    bool has_path = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols
            && board[row][col] == word[path_len] && visited[row][col] == 0) {
        visited[row][col] = 1;
        has_path = existDFS(board, word, rows, cols, row + 1, col, path_len + 1, visited)
                || existDFS(board, word, rows, cols, row - 1, col, path_len + 1, visited)
                || existDFS(board, word, rows, cols, row, col + 1, path_len + 1, visited)
                || existDFS(board, word, rows, cols, row, col - 1, path_len + 1, visited);
        visited[row][col] = 0;
    }
    return has_path;
}

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();
    // 定义二维数组并初始化
    vector<vector<int>> visited(rows, vector<int>(cols, 0));  
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (existDFS(board, word, rows, cols, row, col, 0, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board;
    string word;
    int rows, cols;
    cin >> rows >> cols;
    char x;
    for (int i = 0; i < rows; i++) {
        vector<char> layer;
        for (int j = 0; j < cols; j++) {
            cin >> x;
            layer.push_back(x);
        }
        board.push_back(layer);
    }
    cin >> word;

    if (exist(board, word)) {
        cout << "Exist this path." << endl;
    } else {
        cout << "Don't exits this path!" << endl;
    }
    return 0;
}