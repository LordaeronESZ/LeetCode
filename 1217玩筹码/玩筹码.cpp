#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCnt = 0, evenCnt = 0;
        for (const auto& pos : position) {
            if (pos % 2) ++oddCnt;
            else ++evenCnt;
        }
        return min(oddCnt, evenCnt);
    }
};

int main() {
    Solution S;
    vector<int> position = { 6,4,7,8,2,10,2,7,9,7 };
    auto res = S.minCostToMoveChips(position);
    cout << res << endl;
}