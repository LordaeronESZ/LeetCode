#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // »¬¶¯´°¿Ú
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, product = 1, i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            product *= nums[j];
            while (i <= j && product >= k) {
                product /= nums[i];
                ++i;
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 10,5,2,6 };
    int k = 100;
    auto res = S.numSubarrayProductLessThanK(nums, k);
    cout << res << endl;
}