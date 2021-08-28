#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string result, best_result;
        int l, r;
        for (double i = 0; i <= s.size() - 1; i += 0.5)
        {
            //×Ö·û
            if (int(10 * i) % 10 == 0) {
                l = i - 1, r = i + 1;
                result.push_back(s[i]);

            }
            //×Ö·ûÖÐ¼ä
            else {
                l = i - 0.5, r = i + 0.5;
            }
            while (l >= 0 && r <= s.size() - 1)
            {
                if (s[l] == s[r]) {
                    result.insert(result.begin(), s[l]);
                    result.push_back(s[l]);
                }
                else 
                    break;
                l--, r++;
            }
            if (result.size() > best_result.size()) {
                best_result = result;
            }
            result.clear();
        }
        return best_result;
    }
};
int main() {
    string s;
    cin >> s;
    Solution S;
    string result = S.longestPalindrome(s);
    cout << result << endl;
    return 0;
}