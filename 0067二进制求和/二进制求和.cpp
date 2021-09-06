#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int index_a = int(a.size()) - 1;
        int index_b = int(b.size()) - 1;
        string c = "";
        bool isCarry = false;
        while (index_a >= 0 && index_b >= 0)
        {
            if (a[index_a] == '1' && b[index_b] == '1') {
                if (isCarry)
                    c.insert(c.begin(), '1');
                else
                    c.insert(c.begin(), '0');
                isCarry = true;
            }
            else if (a[index_a] == '0' && b[index_b] == '0') {
                if (isCarry)
                    c.insert(c.begin(), '1');
                else
                    c.insert(c.begin(), '0');
                isCarry = false;
            }
            else {
                if (isCarry)
                    c.insert(c.begin(), '0');
                else
                    c.insert(c.begin(), '1');
            }
            index_a--;
            index_b--;
        }
        while (index_a >= 0) {
            if (a[index_a] == '1') {
                if (isCarry)
                    c.insert(c.begin(), '0');
                else
                    c.insert(c.begin(), '1');
            }
            else {
                if (isCarry)
                    c.insert(c.begin(), '1');
                else
                    c.insert(c.begin(), '0');
                isCarry = false;
            }
            index_a--;
        }
        while (index_b >= 0) {
            if (b[index_b] == '1') {
                if (isCarry)
                    c.insert(c.begin(), '0');
                else
                    c.insert(c.begin(), '1');
            }
            else {
                if (isCarry)
                    c.insert(c.begin(), '1');
                else
                    c.insert(c.begin(), '0');
                isCarry = false;
            }
            index_b--;
        }
        if (isCarry)
            c.insert(c.begin(), '1');
        return c;
    }
};
int main() {
    string a = "101111";
    string b = "10";
    Solution S;
    string c = S.addBinary(a, b);
    cout << c << endl;
    return 0;
}