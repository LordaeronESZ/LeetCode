#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (auto j = i + 1; j < nums.size() - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int m = j + 1, n = nums.size() - 1;
                while (m < n) {
                    if (nums[i] + nums[j] + nums[m] + nums[n] > target)
                        n--;
                    else if (nums[i] + nums[j] + nums[m] + nums[n] < target)
                        m++;
                    else {
                        res.push_back({ nums[i], nums[j], nums[m], nums[n] });
                        while (m < n && nums[m] == nums[m + 1])
                            m++;
                        while (m < n && nums[n] == nums[n - 1])
                            n--;
                        m++, n--;
                    }

                }

            }
        }
        return res;
    }
};
int main() {
    vector<int> nums = { 1000000000, 1000000000, 1000000000, 1000000000 };
    int target = 0;
    Solution S;
    vector<vector<int>> res = S.fourSum(nums, target);
    for (auto i = 0; i < res.size(); i++)
    {
        for (auto j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}