#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        unordered_map<int, int> numMap = { {0,1} };
        int pre = 0;
        for (int i = 0; i < n; i++) {
            pre += nums[i];
            res += numMap[pre - k];
            numMap[pre]++;
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,1,1,1,2,3 };
    int k = 3;
    auto res = S.subarraySum(nums, k);
    cout << res << endl;
    return 0;
}