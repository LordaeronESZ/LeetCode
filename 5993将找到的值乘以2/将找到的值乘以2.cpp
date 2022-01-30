#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (const auto& num : nums) {
            if (num > original)
                break;
            else if (num == original)
                original *= 2;
        }
        return original;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 5,3,6,1,12 };
    int original = 3;
    auto res = S.findFinalValue(nums, original);
    cout << res << endl;
    return 0;
}