#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        map<int, int> cntMap;
        map<int, int> freqMap;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cntMap[nums[i]] > 0) {
                --freqMap[cntMap[nums[i]]];
            }
            ++cntMap[nums[i]];
            maxFreq = max(maxFreq, cntMap[nums[i]]);
            ++freqMap[cntMap[nums[i]]];
            if (maxFreq == 1 || freqMap[maxFreq] * maxFreq + freqMap[maxFreq - 1] * (maxFreq - 1) == i + 1
                && freqMap[maxFreq] == 1 || freqMap[maxFreq] * maxFreq + 1 == i + 1 && freqMap[1] == 1) {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 2,2,1,1,5,3,3,5 };
    auto res = S.maxEqualFreq(nums);
    cout << res << endl;
}