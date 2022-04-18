#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int num = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = num;
            if (num * 10 <= n) {
                num *= 10;
            }
            else {
                while (num % 10 == 9 || num + 1 > n)
                    num /= 10;
                ++num;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 10;
    auto res = S.lexicalOrder(n);
    for (const auto& re : res) {
        cout << re << " ";
    }
}