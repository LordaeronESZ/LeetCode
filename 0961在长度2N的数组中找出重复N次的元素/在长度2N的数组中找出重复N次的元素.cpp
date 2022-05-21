#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //int repeatedNTimes(vector<int>& nums) { // ¹şÏ£±í
    //    unordered_map<int, int> numMap;
    //    for (const auto& num : nums) {
    //        ++numMap[num];
    //    }
    //    for (const auto& num : nums) {
    //        if (numMap[num] > 1) {
    //            return num;
    //        }
    //    }
    //    return -1;
    //}
    int repeatedNTimes(vector<int>& nums) { // Ëæ»úÑ¡Ôñ
        srand((unsigned)time(nullptr));
        while (true) {
            int r1 = rand() % nums.size();
            int r2 = rand() % nums.size();
            if (r1 != r2 && nums[r1] == nums[r2])
                return nums[r1];
        }
        return -1;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 5, 1, 5, 2, 5, 3, 5, 4 };
    auto res = S.repeatedNTimes(nums);
    cout << res << endl;
}