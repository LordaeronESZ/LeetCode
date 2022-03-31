#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        auto isLegal = [](const int& num) -> bool {
            int n = num;
            while (n > 0) {
                int digit = n % 10;
                if (!digit || num % digit)
                    return false;
                n /= 10;
            }
            return true;
        };

        vector<int> res;
        for (int i = left; i <= right; ++i) {
            if (isLegal(i))
                res.emplace_back(i);
        }
        return res;
    }
};
int main() {
    Solution S;
    int left = 1, right = 22;
    auto res = S.selfDividingNumbers(left, right);
    for (const auto& r : res) {
        cout << r << " ";
    }
}