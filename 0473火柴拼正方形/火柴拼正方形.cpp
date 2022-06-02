#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    bool dfs(int index, vector<int>& matchsticks, vector<int>& edges, int len) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // ¼õÉÙËÑË÷Á¿

        vector<int> edges(4);
        return dfs(0, matchsticks, edges, totalLen / 4);
    }
};

int main() {
    Solution S;
    vector<int> matchsticks = { 1,1,2,2,2 };
    auto res = S.makesquare(matchsticks);
    cout << res << endl;
}