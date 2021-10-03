#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = (rolls.size() + n) * mean;
        int rolls_sum = 0;
        vector<int> res;
        for (auto const& r : rolls)
            rolls_sum += r;
        int res_sum = sum - rolls_sum;
        int temp_n = n;
        while(res.size() < n) {
            int k;
            for (k = 1; k <= 6; k++) {
                if (res_sum - k >= (temp_n - 1) * 1 && res_sum - k <= (temp_n - 1) * 6) {
                    res.emplace_back(k);
                    temp_n--;
                    res_sum -= k;
                    break;
                }
            }
            if (k > 6) {
                return {};
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> rolls = { 1,5,6 };
    int mean = 3, n = 4;
    auto res = S.missingRolls(rolls, mean, n);
    for (auto const& r : res)
        cout << r << " ";
    return 0;
}