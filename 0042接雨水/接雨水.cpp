#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        int maxValue = INT32_MIN;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > maxValue)
                maxValue = height[i];
            leftMax[i] = maxValue;
        }
        maxValue = INT32_MIN;
        for (int i = height.size() - 1; i >= 0; i--) {
            if (height[i] > maxValue)
                maxValue = height[i];
            rightMax[i] = maxValue;
        }
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    auto res = S.trap(height);
    cout << res << endl;
    return 0;
}