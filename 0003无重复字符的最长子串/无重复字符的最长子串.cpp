#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string result;
        int best_lenght = 0;
        for (auto it = s.begin(); it < s.end(); it++)
        {
            auto flag = result.find_first_of(*it);
            if (flag != string::npos) {
                result = result.substr(flag + 1);
                result.push_back(*it);
            }
            else
                result.push_back(*it);
            if (result.length() > best_lenght)
                best_lenght = result.length();
        }
        return best_lenght;
    }
};
int main() {
    Solution S;
    string str;
    cin >> str;
    int result = S.lengthOfLongestSubstring(str);
    cout << result << endl;
    return 0;
}