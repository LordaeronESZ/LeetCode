#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> res;
        int curVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                curVal++;
        }
        int maxVal = curVal;
        res.emplace_back(0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                curVal++;
            else if (nums[i] == 1)
                curVal--;
            if (curVal == maxVal)
                res.emplace_back(i + 1);
            else if (curVal > maxVal) {
                maxVal = curVal;
                res.clear();
                res.emplace_back(i + 1);
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 0,0,1,0 };
    auto res = S.maxScoreIndices(nums);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}