#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> newNums(maxVal + 1);
        for (const auto& num : nums) {
            newNums[num] += num;
        }
        vector<int> res(newNums.size());
        if (newNums.size() == 1)
            return newNums[0];
        res[0] = newNums[0];
        res[1] = max(newNums[0], newNums[1]);
        for (size_t i = 2; i < newNums.size(); i++) {
            res[i] = max(res[i - 2] + newNums[i], res[i - 1]);
        }
        return res.back();
    }
};
int main() {
    Solution S;
    vector<int> nums = { 2,2,3,3,3,4 };
    auto res = S.deleteAndEarn(nums);
    cout << res << endl;
    return 0;
}