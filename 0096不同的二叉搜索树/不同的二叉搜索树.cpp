#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> list(n + 1);
        list[0] = 1;
        list[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                list[i] += list[j - 1] * list[i - j];
            }
        }
        return list[n];
    }
};
int main() {
    Solution S;
    int n = 3;
    auto res = S.numTrees(n);
    cout << res << endl;
    return 0;
}