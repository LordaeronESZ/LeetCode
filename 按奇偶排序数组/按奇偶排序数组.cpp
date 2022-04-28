#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
#if 0
    // O(n) O(n)
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd, even;
        for (const auto& num : nums) {
            if (num % 2)
                odd.emplace_back(num);
            else
                even.emplace_back(num);
        }
        for (const auto& o : odd) {
            even.emplace_back(o);
        }
        return even;
    }
#endif
    // O(n) O(1)
    vector<int> sortArrayByParity(vector<int>& nums) {
        int p = 0, q = nums.size() - 1;
        while (p < q) {
            while (p < q && nums[p] % 2 == 0)
                ++p;
            while (p < q && nums[q] % 2 == 1)
                --q;
            swap(nums[p++], nums[q--]);
        }
        return nums;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 3,1,2,4 };
    auto res = S.sortArrayByParity(nums);
    for (const auto& re : res) {
        cout << re << " ";
    }
}