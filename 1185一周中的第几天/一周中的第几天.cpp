#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isLeap(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return true;
        else
            return false;
    }
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> dayList = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
        int daySum = 4;
        for (int i = 1970; i < year; i++) {
            daySum += isLeap(i) ? 366 : 365;
        }
        for (int i = 1; i < month; i++) {
            switch (i)
            {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                daySum += 31; break;
            case 2:
                daySum += isLeap(year) ? 29 : 28; break;
            default:
                daySum += 30; break;
            }
        }
        daySum += day - 1;
        return dayList[daySum % dayList.size()];
    }
};
int main() {
    Solution S;
    int year = 1970, month = 1, day = 1;
    auto res = S.dayOfTheWeek(day, month, year);
    cout << res << endl;
    return 0;
}