#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int startTime = timeSeries.front();
        for (size_t i = 1; i < timeSeries.size(); i++) {
            if (timeSeries[i] - timeSeries[i - 1] > duration) {
                res += timeSeries[i - 1] - startTime + duration;
                startTime = timeSeries[i];
            }
        }
        return res + timeSeries.back() - startTime + duration;
    }
};
int main() {
    Solution S;
    vector<int> timeSeries = { 1,2,3,4,7 };
    int duration = 2;
    auto res = S.findPoisonedDuration(timeSeries, duration);
    cout << res << endl;
    return 0;
}