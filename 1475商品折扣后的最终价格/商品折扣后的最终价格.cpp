#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        for (int i = 0; i < prices.size(); ++i) {
            int j = i + 1;
            while (j < prices.size() && prices[j] > prices[i]) ++j;
            if (j == prices.size()) {
                res.emplace_back(prices[i]);
            }
            else {
                res.emplace_back(prices[i] - prices[j]);
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> prices = { 8,4,6,2,3 };
    auto res = S.finalPrices(prices);
    for (const auto& re : res) {
        cout << re << " ";
    }
}