#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> r;
        Func(res, r, n, k, 1);
        return res;
    }
    void Func(vector<vector<int>>& res, vector<int>& r, int n, int k, int cur_k) {
        if (r.size() + (n - cur_k + 1) < k)
            return;
        if (r.size() == k) {
            res.push_back(r);
            return;
        }
        r.push_back(cur_k);
        Func(res, r, n, k, cur_k + 1);
        r.pop_back();
        Func(res, r, n, k, cur_k + 1);
    }
};
int main() {
    Solution S;
    int n = 3, k = 2;
    auto res = S.combine(n, k);
    for (auto const& re : res) {
        for (auto const& r : re)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}
