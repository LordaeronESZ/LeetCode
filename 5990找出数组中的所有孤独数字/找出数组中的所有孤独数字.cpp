#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> numsMap;
        for (int i = 0; i < nums.size(); i++) {
            numsMap[nums[i]]++;
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (numsMap[nums[i]] == 1) {
                if (numsMap.count(nums[i] - 1) == 0 && numsMap.count(nums[i] + 1) == 0)
                    res.emplace_back(nums[i]);
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 10,6,5,8 };
    auto res = S.findLonely(nums);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}