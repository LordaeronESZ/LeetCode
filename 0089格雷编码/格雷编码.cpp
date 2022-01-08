#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2, n); i++) {
            int tempVal = i ^ (i / 2);
            res.emplace_back(tempVal);
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 3;
    auto res = S.grayCode(n);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}