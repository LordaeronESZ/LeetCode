#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res;
        int rollNum = rolls.size();
        int lastSum = mean * (rollNum + n) - accumulate(rolls.begin(), rolls.end(), 0);
        while (lastSum && n) {
            int avg = lastSum / n--;
            if (avg < 1 || avg > 6)
                return {};
            lastSum -= avg;
            res.emplace_back(avg);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> rolls = { 1,5,6 };
    int mean = 3, n = 4;
    auto res = S.missingRolls(rolls, mean, n);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}