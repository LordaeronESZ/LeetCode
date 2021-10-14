#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        for (auto it = nums.begin() + 1; it < nums.end(); it++) {
            if (*it == *(it - 1)) {
                count++;
                if (count > 2)
                    it = nums.erase(it) - 1;
            }
            else
                count = 1;
        }
        return nums.size();
    }
};
int main() {
    Solution S;
    vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
    S.removeDuplicates(nums);
    for (const auto& n : nums)
        cout << n << " ";
    return 0;
}