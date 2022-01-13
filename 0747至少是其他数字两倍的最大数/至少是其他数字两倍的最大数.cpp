#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int biggest = nums.front(), second = INT32_MIN, bigIndex = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > biggest) {
                second = biggest;
                biggest = nums[i];
                bigIndex = i;
            }
            else if (nums[i] > second) {
                second = nums[i];
            }
        }
        int doubleSecond = second << 1;
        return biggest >= doubleSecond ? bigIndex : -1;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 3,0,0,2 };
    auto res = S.dominantIndex(nums);
    cout << res << endl;
    return 0;
}