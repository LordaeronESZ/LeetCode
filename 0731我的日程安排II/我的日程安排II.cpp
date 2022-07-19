#include<iostream>
#include<vector>
using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int, int>> calendar;
    vector<pair<int, int>> overlaps;
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        for (const auto& overlap : overlaps) {
            if (overlap.first < end && overlap.second > start)
                return false;
        }
        for (const auto& date : calendar) {
            if (date.first < end && date.second > start) {
                overlaps.emplace_back(max(start, date.first), min(end, date.second));
            }
        }
        calendar.emplace_back(start, end);
        return true;
    }
};

int main() {
    MyCalendarTwo myCalendarTwo;
    cout << myCalendarTwo.book(10, 20) << endl; 
    cout << myCalendarTwo.book(50, 60) << endl; 
    cout << myCalendarTwo.book(10, 40) << endl;
    cout << myCalendarTwo.book(5, 15) << endl;
    cout << myCalendarTwo.book(5, 10) << endl;
    cout << myCalendarTwo.book(25, 55) << endl;
}