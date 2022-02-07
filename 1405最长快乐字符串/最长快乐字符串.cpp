#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first)
                return p1.second > p2.second;
            else
                return p1.first > p2.first;
        };

        string res;
        vector<pair<int, int>> numVec = { {a, 0}, {b, 1}, {c, 2} };
        sort(numVec.begin(), numVec.end(), cmp);
        string oriRes;
        while (numVec[0].first) {
            for (int i = 0; i < numVec.size(); i++) {
                int& cnt = numVec[i].first;
                char ch = numVec[i].second + 'a';
                int ind = res.size();
                if (ind < 2 || (!(res[ind - 1] == ch && res[ind - 2] == ch) && cnt > 0)) {
                    res += ch;
                    cnt--;
                    break;
                }
            }
            if (oriRes == res)
                return res;
            else
                oriRes = res;
            sort(numVec.begin(), numVec.end(), cmp);
            //cout << res << endl;
            //printf("此时%c有%d个，%c有%d个，%c有%d个。\n", numVec[0].second + 'a', numVec[0].first
            //    , numVec[1].second + 'a', numVec[1].first, numVec[2].second + 'a', numVec[2].first);
        }
        return res;
    }
};
int main() {
    Solution S;
    int a = 1, b = 1, c = 7;
    auto res = S.longestDiverseString(a, b, c);
    cout << res << endl;
    return 0;
}