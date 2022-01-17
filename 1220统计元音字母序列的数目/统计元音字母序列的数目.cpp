#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
class Solution {
public:
    int countVowelPermutation(int n) {
        // dp[i]['c'] 表示长度为 i + 1 且末尾字符为 'c' 的个数
        vector<unordered_map<char, long long>> dp(n);
        dp[0]['a'] = 1; dp[0]['e'] = 1; dp[0]['i'] = 1;
        dp[0]['o'] = 1; dp[0]['u'] = 1;
        for (int i = 1; i < n; i++) {
            dp[i]['a'] = (dp[i - 1]['e'] + dp[i - 1]['i'] + dp[i - 1]['u']) % static_cast<long long>((1e9 + 7));
            dp[i]['e'] = (dp[i - 1]['a'] + dp[i - 1]['i']) % static_cast<long long>((1e9 + 7));
            dp[i]['i'] = (dp[i - 1]['e'] + dp[i - 1]['o']) % static_cast<long long>((1e9 + 7));
            dp[i]['o'] = dp[i - 1]['i'] % static_cast<long long>((1e9 + 7));
            dp[i]['u'] = (dp[i - 1]['i'] + dp[i - 1]['o']) % static_cast<long long>((1e9 + 7));
        }
        int res = (dp[n - 1]['a'] + dp[n - 1]['e'] + dp[n - 1]['i'] + dp[n - 1]['o'] + dp[n - 1]['u'])
            % static_cast<long long>(1e9 + 7);
        return res;
    }
};
int main() {
    Solution S;
    int n = 144;
    auto res = S.countVowelPermutation(n);
    cout << res << endl;
    return 0;
}