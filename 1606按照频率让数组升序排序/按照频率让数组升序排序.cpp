#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> numCnt;
        for (int i = 0; i < nums.size(); ++i) {
            ++numCnt[nums[i]];
        }
        vector<int> res;
        vector<pair<int, int>> cntVec;
        for (const auto& nc : numCnt) {
            cntVec.emplace_back(nc.first, nc.second);
        }
        sort(cntVec.begin(), cntVec.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.second == p2.second) return p1.first > p2.first;
            return p1.second < p2.second; 
            });
        for (auto& cv : cntVec) {
            while (cv.second > 0) {
                res.emplace_back(cv.first);
                --cv.second;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { -1,1,-6,4,5,-6,1,4,1 };
    auto res = S.frequencySort(nums);
    for (const auto& re : res) {
        cout << re << " ";
    }
}