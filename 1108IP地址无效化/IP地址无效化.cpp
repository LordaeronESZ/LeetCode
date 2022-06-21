#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (int i = 0; i < address.size(); ++i) {
            if (address[i] == '.') {
                res += '[';
                res += address[i];
                res += ']';
            }
            else {
                res += address[i];
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    string address = "255.100.50.0";
    auto res = S.defangIPaddr(address);
    cout << res << endl;
}