#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int p1 = 0, p2 = 0;
        while (p1 < start.size() && p2 < end.size()) {
            while (p1 < start.size() && start[p1] == 'X') {
                ++p1;
            }
            while (p2 < end.size() && end[p2] == 'X') {
                ++p2;
            }
            if (start[p1] != end[p2]) {
                return false;
            }
            else if (start[p1] == 'L') {
                if (p1 < p2) {
                    return false;
                }
            }
            else if (start[p1] == 'R') {
                if (p1 > p2) {
                    return false;
                }
            }
            ++p1;
            ++p2;
        }
        while (p1 < start.size() && start[p1] == 'X') {
            ++p1;
        }
        while (p2 < end.size() && end[p2] == 'X') {
            ++p2;
        }
        if (p1 < start.size() || p2 < end.size()) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution S;
    string start = "XRXXXLXXXR";
    string end = "XXRLXXXRXX";
    auto res = S.canTransform(start, end);
    cout << res << endl;
}