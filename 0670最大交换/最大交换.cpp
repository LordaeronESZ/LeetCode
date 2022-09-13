#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        for (int i = 0; i < str.size(); ++i) {
            char maxDigit = '0', maxInd = i + 1;
            for (int j = i + 1; j < str.size(); ++j) {
                if (maxDigit <= str[j]) {
                    maxDigit = str[j];
                    maxInd = j;
                }
            }
            if (maxDigit > str[i]) {
                swap(str[i], str[maxInd]);
                break;
            }
        }
        return stoi(str);
    }
};

int main() {
    Solution S;
    int num = 1993;
    auto res = S.maximumSwap(num);
    cout << res << endl;
}

