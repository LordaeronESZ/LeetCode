#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (k > 0) {
            int sum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
            res[0] = sum;
            for (int i = 1; i < n; ++i) {
                int addNum = code[(k + i) % n];
                int subNum = code[i];
                sum = sum + addNum - subNum;
                res[i] = sum;
            }
        }
        else if (k < 0) {
            k *= -1;
            int sum = accumulate(code.end() - k, code.end(), 0);
            res[0] = sum;
            for (int i = 1; i < n; ++i) {
                int addNum = code[i - 1];
                int subNum = code[(i - k - 1 + n) % n];
                sum = sum + addNum - subNum;
                res[i] = sum;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> code = { 2,4,9,3 };
    int k = -2;
    auto res = S.decrypt(code, k);
    for (const auto& re : res) {
        cout << re << " ";
    }
}