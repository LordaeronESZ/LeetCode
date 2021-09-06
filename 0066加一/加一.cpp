#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        int i = int(digits.size() - 1);
        while (i >= 0)
        {
            digits[i] += c;
            if (i == digits.size() - 1)
                digits[i] += 1;
            if (digits[i] == 10) {
                c = 1;
                digits[i] = 0;
            }
            else {
                c = 0;
                break;
            }
            i--;
        }
        if (c == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main() {
    vector<int> digits1 = { 9,9,9 };
    vector<int> digits2 = { 4,3,2,9 };
    vector<int> digits3 = { 0 };
    Solution S;
    vector<int> res = S.plusOne(digits3);
    for (auto r : res)
        cout << r << " ";
    cout << endl;
    return 0;
}
