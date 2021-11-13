#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> res(cost.size());
        res[0] = cost[0];
        res[1] = cost[1];
        if (cost.size() == 2)
            return min(cost[0], cost[1]);
        for (size_t i = 2; i < cost.size(); i++) {
            res[i] = min(res[i - 1], res[i - 2]) + cost[i];
        }
        return min(res[res.size() - 1], res[res.size() - 2]);
    }
};
int main() {
    Solution S;
    vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    vector<int> cost1 = { 10, 15, 20 };
    auto res = S.minCostClimbingStairs(cost1);
    cout << res << endl;
    return 0;
}