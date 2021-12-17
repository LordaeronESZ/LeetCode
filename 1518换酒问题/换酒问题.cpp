#include<iostream>
using namespace std;
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, numEmpty = 0;
        while (numBottles) {
            res += numBottles;
            numEmpty += numBottles;
            numBottles = numEmpty / numExchange;
            numEmpty -= numBottles * numExchange;
        }
        return res;
    }
};
int main() {
    Solution S;
    int numBottles = 15, numExchange = 4;
    auto res = S.numWaterBottles(numBottles, numExchange);
    cout << res << endl;
    return 0;
}