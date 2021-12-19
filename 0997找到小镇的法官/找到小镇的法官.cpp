#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> trustMap;
        unordered_map<int, vector<int>> rtrustMap;
        for (const auto& tru : trust) {
            trustMap[tru.front()].emplace_back(tru.back());
            rtrustMap[tru.back()].emplace_back(tru.front());
        }
        for (int i = 1; i <= n; i++) {
            if (!trustMap.count(i) && (rtrustMap[i].size() == n - 1))
                return i;
        }
        return -1;
    }
};
int main() {
    Solution S;
    int n = 4;
    vector<vector<int>> trust = { {1,3},{1,4},{2,3},{2,4},{4,3} };
    auto res = S.findJudge(n, trust);
    cout << res << endl;
    return 0;
}