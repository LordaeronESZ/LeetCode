#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        for (int i = 1; i <= nums.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); ++j) {
                cnt += nums[j] >= i;
            }
            if (cnt == i) {
                return cnt;
            }
        }
        return -1;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 0,4,3,0,4 };
    auto res = S.specialArray(nums);
    cout << res << endl;
}