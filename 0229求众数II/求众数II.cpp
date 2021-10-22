#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> numMap;
        vector<int> res;
        for (const auto& num : nums) {
            numMap[num]++;
        }
        for (const auto& nm : numMap) {
            if (nm.second > nums.size() / 3)
                res.emplace_back(nm.first);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,1,1,3,3,2,2,2 };
    auto res = S.majorityElement(nums);
    for (const auto& r : res) {
        cout << r << " ";
    }
    return 0;
}