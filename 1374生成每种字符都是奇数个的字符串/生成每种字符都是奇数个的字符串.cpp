#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        string res;
        if (n % 2 == 1) {
            res += string(n, 'a');
        }
        else {
            res += string(n - 1, 'a');
            res += 'b';
        }
        return res;
    }
};

int main() {
    Solution S;
    int n = 4;
    auto res = S.generateTheString(n);
    cout << res << endl;
}