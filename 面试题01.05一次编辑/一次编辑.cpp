#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.size(), n = second.size();
        if (m == n) {
            int diff = 0;
            for (int i = 0; i < m; ++i) {
                diff += (first[i] != second[i]);
            }
            if (diff >= 2) return false;
            return true;
        }
        else if (m == n - 1) {
            bool flag = false;
            for (int i = 0; i < n; ++i) {
                string ns = second.substr(0, i) + second.substr(i + 1);
                if (ns == first) {
                    flag = true;
                    break;
                }
            }
            return flag;
        }
        else if (m == n + 1) {
            bool flag = false;
            for (int i = 0; i < m; ++i) {
                string ns = first.substr(0, i) + first.substr(i + 1);
                if (ns == second) {
                    flag = true;
                    break;
                }
            }
            return flag;
        }
        else return false;
    }
};

int main() {
    Solution S;
    string first = "pales";
    string second = "pal";
    auto res = S.oneEditAway(first, second);
    cout << res << endl;
}