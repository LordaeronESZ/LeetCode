#include<iostream>
#include<string>
using namespace std;

class Solution {
private:
    int singleCharAnswers(const string& answerKey, int k, char chr) {
        int n = answerKey.size(), res = 0;
        for (int left = 0, right = 0, sum = 0; right < n; ++right) {
            if (answerKey[right] != chr)
                ++sum;
            while (k < sum) {
                if (answerKey[left] != chr)
                    sum--;
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res1 = singleCharAnswers(answerKey, k, 'T');
        int res2 = singleCharAnswers(answerKey, k, 'F');
        return max(res1, res2);
    }
};
int main() {
    Solution S;
    string key = "TTFTTFTT";
    int k = 1;
    auto res = S.maxConsecutiveAnswers(key, k);
    cout << res << endl;
    return 0;
}