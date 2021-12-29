#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    for (int l = k + 1; l < nums.size(); l++) {
                        if (nums[i] + nums[j] + nums[k] == nums[l])
                            res++;
                    }
                }
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,1,1,3,5 };
    auto res = S.countQuadruplets(nums);
    cout << res << endl;
    return 0;
}