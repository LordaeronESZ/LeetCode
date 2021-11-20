#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> numMap;
        sort(nums.begin(), nums.end());
        for (const auto& num : nums) {
            numMap[num]++;
            if(numMap.find(num - 1) != numMap.end())
                maxLength = max(maxLength, numMap[num] + numMap[num - 1]);
        }
        return maxLength;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,3,2,2,5,2,3,7 };
    vector<int> nums1 = { 1,1,1,1 };
    auto res = S.findLHS(nums1);
    cout << res << endl;
    return 0;
}