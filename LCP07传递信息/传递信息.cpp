#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    int dfs(int n, vector<vector<int>>& relation, int k, int i) {
        if (relation[i][1] == n - 1 && !k)
            return 1;
        else if (!k)
            return 0;
        int res = 0;
        for (int j = 0; j < relation.size(); j++) {
            if (relation[j][0] == relation[i][1]) {
                res += dfs(n, relation, k - 1, j);
            }
        }
        return res;
    }
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        int res = 0;
        for (int i = 0; i < relation.size(); i++) {
            if (!relation[i][0]) {
                res += dfs(n, relation, k - 1, i);
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 5, k = 3;
    vector<vector<int>> relation = { {0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4} };
    auto res = S.numWays(n, relation, k);
    cout << res << endl;
    return 0;
}