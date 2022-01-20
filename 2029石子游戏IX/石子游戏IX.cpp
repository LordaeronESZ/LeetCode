#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (const auto& stone : stones) {
            int type = stone % 3;
            if (type == 0)
                cnt0++;
            else if (type == 1)
                cnt1++;
            else
                cnt2++;
        }
        if (cnt0 % 2 == 0)
            return cnt1 >= 1 && cnt2 >= 1;
        return abs(cnt1 - cnt2) > 2;
    }
};
int main() {
    vector<int> stones = { 5,1,2,4,3 };
    Solution S;
    auto res = S.stoneGameIX(stones);
    cout << res << endl;
    return 0;
}