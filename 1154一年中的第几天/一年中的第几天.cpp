#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int strToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += pow(10, s.size() - i - 1) * (s[i] - '0');
        }
        return res;
    }
    int dayOfYear(string date) {
        string year = date.substr(0, 4), month = date.substr(5, 2), day = date.substr(8, 2);
        int numYear = strToInt(year), numMonth = strToInt(month), numDay = strToInt(day);
        bool isLeap = ((numYear % 4 == 0 && numYear % 100 != 0) || numYear % 400 == 0);
        int res = numDay;
        numMonth--;
        while (numMonth >= 1) {
            switch (numMonth)
            {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                res += 31; break;
            case 2:
                res += isLeap ? 29 : 28; break;
            default:
                res += 30; break;
            }
            numMonth--;
        }
        return res;
    }
};
int main() {
    Solution S;
    string date = "2019-02-10";
    auto res = S.dayOfYear(date);
    cout << res << endl;
    return 0;
}