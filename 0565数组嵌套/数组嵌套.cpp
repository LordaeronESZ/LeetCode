#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            while (!visited[i]) {
                visited[i] = true;
                ++cnt;
                i = nums[i];
            }
            res = max(res, cnt);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 5,4,0,3,1,6,2 };
    auto res = S.arrayNesting(nums);
    cout << res << endl;
}