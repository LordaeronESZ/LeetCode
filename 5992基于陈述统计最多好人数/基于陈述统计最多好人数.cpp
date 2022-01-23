#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int res = 0;
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;
            vector<bool> isGood(n);
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) { // 统计状态 i 的好人与坏人
                    isGood[j] = true;
                    cnt++;
                }
                else
                    isGood[j] = false;
            }
            // 验证状态是否合理
            bool isLegal = true;
            for (int j = 0; j < n; j++) {
                if (isGood[j]) { // 若 j 是好人，则遍历他的陈述是否正确
                    for (int k = 0; k < n; k++) {
                        if (statements[j][k] == 1 && !isGood[k]) {
                            isLegal = false;
                            break;
                        }
                        if (statements[j][k] == 0 && isGood[k]) {
                            isLegal = false;
                            break;
                        }
                    }
                }
            }
            if(isLegal)
                res = max(res, cnt);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> statements = { {2,1,2},{1,2,2},{2,0,2} };
    auto res = S.maximumGood(statements);
    cout << res << endl;
    return 0;
}