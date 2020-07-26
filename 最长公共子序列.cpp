#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

vector<vector<int>> lengthOfLCS(string nums1, string nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i < n1 + 1; i++) {
        for (int j = 1; j < n2 + 1; j++) {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    // return dp[n1][n2];
    return dp;
}

void printLCS(string nums1, string nums2, int i, int j, vector<char> path, vector<vector<int>> dp, set<vector<char>> &res_path) {
    while (i > 0 && j > 0) {
        if (nums1[i - 1] == nums2[j - 1]) {
            path.push_back(nums1[i - 1]);
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else if (dp[i - 1][j] < dp[i][j - 1])
                j--;
            else {
                printLCS(nums1, nums2, i - 1, j, path, dp, res_path);
                printLCS(nums1, nums2, i, j - 1, path, dp, res_path);
                return;
            }
        }
    }
    reverse(path.begin(), path.end());
    res_path.insert(path);
}

int main() {
    string nums1, nums2;
    cin >> nums1;
    cin >> nums2;
    vector<vector<int>> dp = lengthOfLCS(nums1, nums2);
    // 打印最长公共子序列的长度
    cout << dp[nums1.size()][nums2.size()] << endl;
    vector<char> path;
    set<vector<char>> res_path;
    printLCS(nums1, nums2, nums1.size(), nums2.size(), path, dp, res_path);
    for (set<vector<char>>::iterator iter = res_path.begin(); iter != res_path.end(); iter++) {
		vector<char> cur = *iter;
        for (vector<char>::iterator it = cur.begin(); it != cur.end(); it++) {
            cout << *it << "";
        }
        cout << endl;
    }
}