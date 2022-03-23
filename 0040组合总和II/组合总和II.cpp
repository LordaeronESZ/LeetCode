#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    void search(vector<int>& candidates, int target, int ind) {
        if (!target) {
            res.emplace_back(temp);
            return;
        }
        for (int i = ind; i < candidates.size(); ++i) {
            if (candidates[i] > target)
                break;
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;
            temp.emplace_back(candidates[i]);
            search(candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        search(candidates, target, 0);
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