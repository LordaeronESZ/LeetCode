#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    int res, maxVal, n;
    void search(vector<int>& nums, int pos, int sum) {
        if (pos == n) {
            if (sum == maxVal) {
                res++;
            }
            else if (sum > maxVal) {
                res = 1;
                maxVal = sum;
            }
            return;
        }
        search(nums, pos + 1, sum | nums[pos]);
        search(nums, pos + 1, sum);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        res = 0, maxVal = INT32_MIN;
        n = nums.size();
        search(nums, 0, 0);
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 3,2,1,5 };
    auto res = S.countMaxOrSubsets(nums);
    cout << res << endl;
    return 0;
}