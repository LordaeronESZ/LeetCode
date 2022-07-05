#include<iostream>
#include<vector>
using namespace std;

class MyCalendar {
private:
    vector<pair<int, int>> calendar;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        bool flag = true;
        for (int i = 0; i < calendar.size(); ++i) {
            if (!(start >= calendar[i].second || end <= calendar[i].first)) {
                flag = false;
                break;
            }
        }
        if (flag)
            calendar.emplace_back(start, end);
        return flag;
    }
};

int main() {
    MyCalendar myCalendar;
    cout << myCalendar.book(10, 20) << endl; // return True
    cout << myCalendar.book(15, 25) << endl; // return False ，这个日程安排不能添加到日历中，因为时间 15 已经被另一个日程安排预订了。
    cout << myCalendar.book(20, 30) << endl; // return True ，这个日程安排可以添加到日历中，因为第一个日程安排预订的每个时间都小于 20 ，且不包含时间 20 。
}