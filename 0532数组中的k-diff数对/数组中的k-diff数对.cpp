#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        set<pair<int, int>> numSet;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int diff = abs(nums[i] - nums[j]);
                if (diff == k && numSet.count(make_pair(nums[i],nums[j])) == 0) {
                    ++res;
                    numSet.emplace(nums[i], nums[j]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 3, 1, 4, 1, 5 };
    int k = 2;
    auto res = S.findPairs(nums, k);
    cout << res << endl;
}