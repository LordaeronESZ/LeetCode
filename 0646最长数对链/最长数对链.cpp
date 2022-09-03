#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return p1[1] < p2[1]; });
        int res = 0, tail = INT32_MIN;
        for (int i = 0; i < pairs.size(); ++i) {
            if (tail < pairs[i][0]) {
                ++res;
                tail = pairs[i][1];
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> pairs = { {1,2},{7,8},{4,5} };
    auto res = S.findLongestChain(pairs);
    cout << res << endl;
}