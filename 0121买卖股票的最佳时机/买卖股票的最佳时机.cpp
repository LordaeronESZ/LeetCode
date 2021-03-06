#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices.front();
        int res = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> prices = { 7,1,5,3,6,4 };
    vector<int> prices2 = { 7,6,4,3,1 };
    auto res = S.maxProfit(prices);
    cout << res << endl;
    return 0;
}