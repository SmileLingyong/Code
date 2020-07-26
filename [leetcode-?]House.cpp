#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define inf 0x3fffffff

int Func(int n, vector<int> house) {
    int left = 0;
    int sum = 0;
    int res = __INT_MAX__;
    for (int i = 0; i < house.size(); i++) {
        sum += house[i];
        while (sum >= n) {
            res = res > i - left + 1 ? i - left + 1 : res;
            sum -= house[left++];
        }
    }
    if (res == __INT_MAX__) 
        res = 0;
    return res;
}

int main() {
    int n, x, res;
    vector<int> house;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        house.push_back(x);
    }
    res = Func(n, house);
    cout << res; 
    return 0;
}