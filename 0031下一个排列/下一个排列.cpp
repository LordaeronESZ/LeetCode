#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (auto it = nums.end() - 1; it >= nums.begin(); it--) {
            if (it - 1 >= nums.begin() && *(it - 1) < *it) {
                auto minValue = it;
                for (auto jt = it + 1; jt < nums.end(); jt++) {
                    if (*jt < *minValue && *jt > *(it - 1))
                        minValue = jt;
                }
                swap(*minValue, *(it - 1));
                sort(it, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,2,3,4,2 };
    S.nextPermutation(nums);
    for (const auto& num : nums) {
        cout << num << " ";
    }
    return 0;
}