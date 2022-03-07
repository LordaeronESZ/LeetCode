#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> res;
        vector<int> forVec(n);
        vector<int> revVec(n);
        forVec[0] = 0;
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1])
                forVec[i] = forVec[i - 1] + 1;
            else
                forVec[i] = 0;
        }
        revVec[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1])
                revVec[i] = revVec[i + 1] + 1;
            else
                revVec[i] = 0;
        }
        for (int i = time; i < n - time; i++) {
            if (forVec[i] >= time && revVec[i] >= time)
                res.emplace_back(i);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> security = { 4,3,2,1 };
    int time = 1;
    auto res = S.goodDaysToRobBank(security, time);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}