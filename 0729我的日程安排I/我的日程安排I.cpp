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
    cout << myCalendar.book(15, 25) << endl; // return False ������ճ̰��Ų�����ӵ������У���Ϊʱ�� 15 �Ѿ�����һ���ճ̰���Ԥ���ˡ�
    cout << myCalendar.book(20, 30) << endl; // return True ������ճ̰��ſ�����ӵ������У���Ϊ��һ���ճ̰���Ԥ����ÿ��ʱ�䶼С�� 20 ���Ҳ�����ʱ�� 20 ��
}