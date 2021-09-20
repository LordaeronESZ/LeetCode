#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> add_res;
        Func(res, candidates, add_res, target, 0);
        return res;
    }
    void Func(vector<vector<int>>& res, vector<int>& candidates, vector<int>& add_res, int target, int index) {
        if (index == candidates.size())
            return;
        if (target == 0) {
            res.push_back(add_res);
            return;
        }
        //²»Ñ¡Ôñ
        Func(res, candidates, add_res, target, index + 1);
        //Ñ¡Ôñ
        if (target >= candidates[index]) {
            add_res.push_back(candidates[index]);
            Func(res, candidates, add_res, target - candidates[index], index);
            add_res.pop_back();
        }
    }
};
int main() {
    vector<int> candidates = { 2,3,6,7 };
    int target = 7;
    Solution S;
    vector<vector<int>> res = S.combinationSum(candidates, target);
    for (auto re : res) {
        for (auto r : re)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}