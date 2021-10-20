#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        int minValue = *min_element(nums.begin(), nums.end());
        for (const auto& num : nums)
            res += num - minValue;
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,2,3 };
    auto res = S.minMoves(nums);
    cout << res << endl;
    return 0;
}