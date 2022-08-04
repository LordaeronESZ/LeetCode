#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        priority_queue<int, vector<int>, less<int>> Q;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            Q.emplace(nums[i]);
        }
        vector<int> res;
        int reSum = 0;
        while (!Q.empty()) {
            int maxVal = Q.top();
            Q.pop();
            res.emplace_back(maxVal);
            sum -= maxVal;
            reSum += maxVal;
            if (reSum > sum) break;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 4,4,7,6,7 };
    auto res = S.minSubsequence(nums);
    for (const auto& re : res) {
        cout << re << " ";
    }
}