#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = INT32_MIN, sum = INT32_MIN;
        for (auto n : nums) {
            if (sum > 0)
                sum += n;
            else
                sum = n;
            if (sum > best_sum)
                best_sum = sum;
        }
        return best_sum;
    }
};
int main() {
    vector<int> nums = { -1 };
    Solution S;
    int res = S.maxSubArray(nums);
    cout << res << endl;
    return 0;
}