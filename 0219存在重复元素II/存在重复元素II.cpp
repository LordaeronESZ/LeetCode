#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numsMap;
        for (int i = 0; i < nums.size(); i++) {
            if (numsMap.find(nums[i]) != numsMap.cend() && abs(numsMap[nums[i]] - i) <= k) {
                return true;
            }
            numsMap[nums[i]] = i;
        }
        return false;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,0,1,1 };
    int k = 1;
    auto res = S.containsNearbyDuplicate(nums, k);
    cout << res << endl;
    return 0;
}