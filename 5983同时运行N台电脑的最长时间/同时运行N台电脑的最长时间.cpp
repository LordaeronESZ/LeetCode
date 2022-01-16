#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        auto canRun = [&](long long t) {
            long long sum = 0;
            for (const auto& battery : batteries) {
                sum += min(static_cast<long long>(battery), t);
            }
            return sum / t >= n;
        };

        long long sumBat = accumulate(batteries.begin(), batteries.end(), 0L);
        long long l = 1, r = sumBat / n + 1;
        while (l < r) {
            long long mid = (l + r) / 2;
            if (canRun(mid))
                l = mid + 1;
            else
                r = mid;
        }
        return l - 1;
    }
};
int main() {
    Solution S;
    int n = 2;
    vector<int> batteries = { 3,3,3 };
    auto res = S.maxRunTime(n, batteries);
    cout << res << endl;
    return 0;
}