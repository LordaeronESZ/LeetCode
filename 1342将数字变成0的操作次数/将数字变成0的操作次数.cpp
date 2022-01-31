#include<iostream>
using namespace std;
class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while (num) {
            if (num % 2 == 0)
                num /= 2;
            else
                num -= 1;
            res++;
        }
        return res;
    }
};
int main() {
    Solution S;
    int num = 14;
    auto res = S.numberOfSteps(num);
    cout << res << endl;
    return 0;
}