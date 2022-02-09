#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> numsMap;
        for (const auto& num : nums) {
            numsMap[num]++;
        }
        for (const auto& num : nums) {
            res += numsMap[num + k];
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,2,2,1 };
    int k = 1;
    auto res = S.countKDifference(nums, k);
    cout << res << endl;
    return 0;
}