#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int best_res = INT32_MAX;
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int res = nums[i] + nums[j] + nums[k] - target;
                if (res < 0)
                    j++;
                else
                    k--;
                if (abs(res) < abs(best_res))
                    best_res = res;
            }
        }
        return best_res + target;
    }
};
int main() {
    vector<int> nums = { -1,2,1,-4 };
    int target = 1;
    Solution S;
    int res = S.threeSumClosest(nums, target);
    cout << res << endl;
}