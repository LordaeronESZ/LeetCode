#include<iostream> 
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> delta(n);
        int ans = 0, m = requests.size();
        for (int mask = 0; mask < (1 << m); ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt <= ans) {
                continue;
            }
            fill(delta.begin(), delta.end(), 0);
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    ++delta[requests[i][0]];
                    --delta[requests[i][1]];
                }
            }
            if (all_of(delta.begin(), delta.end(), [](int x) { return x == 0; })) {
                ans = cnt;
            }
        }
        return ans;
    }
};


int main() {
    Solution S;
    int n = 3;
    vector<vector<int>> requests = {{2, 0}, {2, 1}, {0, 1}, {0, 1}};
    auto res = S.maximumRequests(n, requests);
    cout << res << endl;
}