#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) : nums(nums) {
        sort(nums.begin(), nums.end());
    }

    int pick(int target) {
        int left = 0, right = nums.size() - 1;
        bool start = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (!start && nums[i] == target) {
                start = true;
                left = i;
            }
            else if (start && nums[i] != target) {
                right = i - 1;
                break;
            }
        }
        int res = rand() % (right - left + 1) + left;
        return res;
    }
};

int main() {
    int target = 3;
    vector<int> nums = { 1,2,3,3,3 };
    Solution S(nums);

    // debug
    unordered_map<int, int> dic;
    for (int i = 0; i < 30000; ++i) {
        auto res = S.pick(target);
        ++dic[res];
    }
    for (const auto& d : dic) {
        cout << d.first << ": " << d.second << endl;
    }
}