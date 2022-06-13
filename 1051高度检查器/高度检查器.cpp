#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto heightsCopy = heights;
        sort(heights.begin(), heights.end());
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            res += heights[i] != heightsCopy[i];
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> heights = { 1,1,4,2,1,3 };
    auto res = S.heightChecker(heights);
    cout << res << endl;
}