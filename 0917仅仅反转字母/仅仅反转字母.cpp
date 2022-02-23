#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (isalpha(s[left]) && isalpha(s[right])) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if (isalpha(s[left]))
                right--;
            else if (isalpha(s[right]))
                left++;
            else {
                left++;
                right--;
            }
        }
        return s;
    }
};
int main() {
    Solution S;
    string s = "Test1ng-Leet=code-Q!";
    auto res = S.reverseOnlyLetters(s);
    cout << res << endl;
    return 0;
}