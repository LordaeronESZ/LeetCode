#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string new_s;
        for (int i = 0; i < numRows; i++) {
            int j = i;
            while (j < s.size()) {
                int step1 = 2 * (numRows - i - 1);
                int step2 = 2 * (numRows - 1) - step1;
                if (step1 && j < s.size())
                    new_s.push_back(s[j]);
                j += step1;
                if (step2 && j < s.size())
                    new_s.push_back(s[j]);
                j += step2;
            }
        }
        return new_s;
    }
};
int main() {
    Solution S;
    string s = "PAYPALISHIRING";
    string s2 = "ABCD";
    int numRows = 4;
    string res = S.convert(s2, 1);
    cout << res << endl;
    return 0;
}