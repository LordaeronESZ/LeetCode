#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minSum = INT32_MAX;
        for (const auto& num : nums) {
            sum += num;
            minSum = min(sum, minSum);
        }
        return minSum > 0 ? 1 : 1 - minSum;
    }
};

int main() {
    Solution S;
    vector<int> nums = { -3,2,-3,4,2 };
    auto res = S.minStartValue(nums);
    cout << res << endl;
}