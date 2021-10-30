#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        size_t i = 0, j = 1;
        while (i < nums.size() && j < nums.size()) {
            if (!(nums[i] ^ nums[j])) {
                i += 2;
                j += 2;
            }
            else {
                res.emplace_back(nums[i]);
                if (res.size() >= 2)
                    break;
                i += 1;
                j += 1;
            }
        }
        if (i == nums.size() - 1) {
            res.emplace_back(nums[i]);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,2,1,3,2,5 };
    vector<int> nums2 = { 0,1,2,2 };
    auto res = S.singleNumber(nums2);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}