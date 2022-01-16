#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size());
        dp[questions.size() - 1] = questions.back().front();
        for (int i = questions.size() - 2; i >= 0; i--) {
            if (questions[i][1] + i + 1 < dp.size())
                dp[i] = max(questions[i][0] + dp[i + questions[i][1] + 1], dp[i + 1]);
            else
                dp[i] = max((long long)questions[i][0], dp[i + 1]);
        }
        return dp[0];
    }
};
int main() {
    Solution S;
    vector<vector<int>> questions = { {3,2},{4,3},{4,4},{2,5} };
    auto res = S.mostPoints(questions);
    cout << res << endl;
    return 0;
}