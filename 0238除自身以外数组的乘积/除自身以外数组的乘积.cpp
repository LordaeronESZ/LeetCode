#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> proL(n, 1), proR(n, 1);
        vector<int> res(n);
        proL[0] = 1, proR[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            proL[i] = proL[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            proR[i] = proR[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = proL[i] * proR[i];
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { -1,1,0,-3,3 };
    auto res = S.productExceptSelf(nums);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}