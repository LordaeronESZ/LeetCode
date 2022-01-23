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
                if ((i >> j) & 1) { // ͳ��״̬ i �ĺ����뻵��
                    isGood[j] = true;
                    cnt++;
                }
                else
                    isGood[j] = false;
            }
            // ��֤״̬�Ƿ����
            bool isLegal = true;
            for (int j = 0; j < n; j++) {
                if (isGood[j]) { // �� j �Ǻ��ˣ���������ĳ����Ƿ���ȷ
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