#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.front() == '0' || num2.front() == '0')
            return string("0");
        string res, temp;
        int carry = 0, num = 0;
        for (int i = num2.size() - 1; i >= 0; i--) {
            for (int j = num1.size() - 1; j >= 0; j--) {
                num = (num1[j] - '0') * (num2[i] - '0') + carry;
                carry = num / 10;
                temp.insert(temp.begin(), num % 10 + '0');
            }
            if (carry) {
                temp.insert(temp.begin(), carry + '0');
                carry = 0;
            }
            //Ä©Î²Ìí0
            for (int k = num2.size() - 1; k > i; k--)
                temp.push_back('0');
            res = StringPlus(temp, res);
            temp.clear();
        }
        return res;
    }
    string StringPlus(string s1, string s2) {
        if (s1.empty())
            return s2;
        if (s2.empty())
            return s1;
        string plus_res;
        int temp = 0, carry = 0;
        int it1 = s1.size() - 1;
        int it2 = s2.size() - 1;
        while (it1 >= 0 && it2 >= 0) {
            temp = s1[it1] - '0' + s2[it2] - '0' + carry;
            carry = temp / 10;
            plus_res.insert(plus_res.begin(), temp % 10 + '0');
            it1--;
            it2--;
        }
        while (it1 >= 0) {
            temp = s1[it1] - '0' + carry;
            carry = temp / 10;
            plus_res.insert(plus_res.begin(), temp % 10 + '0');
            it1--;
        }
        while (it2 >= 0) {
            temp = s2[it2] - '0' + carry;
            carry = temp / 10;
            plus_res.insert(plus_res.begin(), temp % 10 + '0');
            it2--;
        }
        if (carry)
            plus_res.insert(plus_res.begin(), carry + '0');
        return plus_res;
    }
};
int main() {
    Solution S;
    string num1 = "10302", num2 = "4560";
    string res = S.multiply(num1, num2);
    cout << res << endl;
    return 0;
}