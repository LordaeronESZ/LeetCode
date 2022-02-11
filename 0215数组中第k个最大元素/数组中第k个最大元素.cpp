#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - k];
    }
};
int main() {
    Solution S;
    vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
    int k = 4;
    auto res = S.findKthLargest(nums, k);
    cout << res << endl;
    return 0;
}