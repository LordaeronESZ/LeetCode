#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string str;
        for (int i = 0; i < number.size(); ++i) {
            if (number[i] >= '0' && number[i] <= '9') {
                str += number[i];
            }
        }
        int n = str.size();
        string res;
        int ind = 0;
        while (ind < n - 4) {
            res += str.substr(ind, 3);
            res += "-";
            ind += 3;
        }
        if (n - ind == 4) {
            res += str.substr(ind, 2);
            res += "-";
            res += str.substr(ind + 2, 2);
        }
        else if (n - ind == 3 || n - ind == 2) {
            res += str.substr(ind, n - ind);
        }
        else if (n - ind == 0) {
            res.pop_back();
        }
        return res;
    }
};

int main() {
    Solution S;
    string number = "12";
    auto res = S.reformatNumber(number);
    cout << res << endl;
}