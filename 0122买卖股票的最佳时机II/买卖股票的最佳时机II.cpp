#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                res += prices[i] - prices[i - 1];
        }
        return res; 
    }
};
int main() {
    Solution S;
    vector<int> prices = { 7,1,5,3,6,4 };
    auto res = S.maxProfit(prices);
    cout << res << endl;
    return 0;
}