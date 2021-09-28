#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int maxStep, index = 0, res = 0;
        while (true) {
            maxStep = nums.at(index);
            if (index + maxStep >= (int)nums.size() - 1)
                break;
            index = max_vec(nums.begin() + index + 1, nums.begin() + index + maxStep + 1) - nums.begin();
            res++;
        }
        return res + 1;
    }
    vector<int>::iterator max_vec(vector<int>::iterator pt, vector<int>::iterator qt) {
        vector<int>::iterator res;
        int maxValue = INT32_MIN;
        for (auto it = pt; it < qt; it++) {
            if (*it + it - pt >= maxValue) {
                res = it;
                maxValue = *it + it - pt;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,1,1,1,1 };//res = 4
    vector<int> nums2 = { 4,1,1,3,1,1,1 }; //res = 2
    vector<int> nums3 = { 10,9,8,7,6,5,4,3,2,1,1,0 }; //res = 2
    auto res = S.jump(nums3);
    cout << res << endl;
    return 0;
}