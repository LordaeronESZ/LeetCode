#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    set<vector<int>> reSet;
    void search(vector<int>& candidates, vector<int>& temp, int target, int ind) {
        if (ind == candidates.size()) {
            int sum = accumulate(temp.begin(), temp.end(), 0);
            if (sum == target)
                reSet.emplace(temp);
            return;
        }
        temp.emplace_back(candidates[ind]);
        search(candidates, temp, target, ind + 1);
        temp.pop_back();
        search(candidates, temp, target, ind + 1);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        search(candidates, temp, target, 0);
        for (const auto& re : reSet)
            res.emplace_back(re);
        return res;
    }
};
int main() {
    Solution S;
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    int target = 8;
    auto res = S.combinationSum2(candidates, target);
    for (const auto& row : res) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}