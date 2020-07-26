#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <cmath>
using namespace std;

void lengthOfLCS(string nums1, string nums2, int &max_len, vector<vector<int>> &dp, set<string> &res_path) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    for (int i = 1; i < n1 + 1; i++) {
        for (int j = 1; j < n2 + 1; j++) {
            if (nums1[i-1] == nums2[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = 0;
            max_len = max(max_len, dp[i][j]);
        }
    }
    for (int i = 1; i < n1 + 1; i++) {
        for (int j = 1; j < n2 + 1; j++) {
            if (dp[i][j] == max_len) {
                res_path.insert(nums1.substr(i - max_len, max_len));
            }
        }
    }
}

int main() {
    string nums1, nums2;
    cin >> nums1;
    cin >> nums2;
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    set<string> res_path;
    int max_len = 0;
    lengthOfLCS(nums1, nums2, max_len, dp, res_path);
    cout << max_len << endl;
    for (set<string>::iterator iter = res_path.begin(); iter != res_path.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}