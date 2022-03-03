#include<iostream>
using namespace std;
class Solution {
public:
    // ตÝน้
    //int addDigits(int num) {
    //    if (num < 10)
    //        return num;
    //    int res = 0;
    //    while (num) {
    //        res += num % 10;
    //        num /= 10;
    //    }
    //    res = addDigits(res);
    //    return res;
    //}

    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
int main() {
    Solution S;
    int num = 38;
    auto res = S.addDigits(num);
    cout << res << endl;
    return 0;
}