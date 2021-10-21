#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices.front();
        vector<int> res(prices.size(), 0);
        for (size_t i = 1; i < prices.size(); i++) {
            res[i] = res[i - 1] > (prices[i] - min_price) ? res[i - 1] : (prices[i] - min_price);
            if (prices[i] < min_price)
                min_price = prices[i];
        }
        return res.back();
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