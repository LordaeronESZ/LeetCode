#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> Q;
        for (int i = 1; i <= n; ++i) {
            Q.emplace(i);
        }
        while (Q.size() > 1) {
            for (int i = 1; i < k; ++i) { // 将首部置于尾部
                Q.emplace(Q.front());
                Q.pop();
            }
            Q.pop();
        }
        return Q.front();
    }
};

int main() {
    Solution S;
    int n = 5, k = 2;
    auto res = S.findTheWinner(n, k);
    cout << res << endl;
}