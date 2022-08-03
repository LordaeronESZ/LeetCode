#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string res = s;
        for (int i = 0; i < s.size(); ++i) {
            s += s.front();
            s.erase(s.begin());
            res = min(res, s);
        }
        return res;
    }
};

int main() {
    Solution S;
    string s = "kuh";
    int k = 1;
    auto res = S.orderlyQueue(s, k);
    cout << res << endl;
}
