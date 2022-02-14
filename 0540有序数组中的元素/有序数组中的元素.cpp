#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return nums[0];
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            if ((mid - l) % 2) {
                if (nums[mid] == nums[mid - 1])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else {
                if (nums[mid] == nums[mid - 1])
                    r = mid - 2;
                else
                    l = mid + 2;
            }
        }
        return nums[l];
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,2,2,3,3 };
    auto res = S.singleNonDuplicate(nums);
    cout << res << endl;
    return 0;
}