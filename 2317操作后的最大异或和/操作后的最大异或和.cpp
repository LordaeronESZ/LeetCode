#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i < pow(10, 8); i *= 2) {
            bool flag = false;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] & i) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                res += i;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 1,2,3,9,2 };
    auto res = S.maximumXOR(nums);
    cout << res << endl;
}