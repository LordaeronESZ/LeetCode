#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 1; i < n - k; ++i) {
            res.emplace_back(i);
        }
        int p = n - k, q = n;
        while (p <= q) {
            res.emplace_back(p);
            if (p != q) {
                res.emplace_back(q);
            }
            ++p;
            --q;
        }
        return res;
    }
};

int main() {
    Solution S;
    int n = 3, k = 1;
    auto res = S.constructArray(n, k);
    for (const auto& re : res) {
        cout << re << " ";
    }
}