#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        //vector<int> res(n, 1);
        //for (size_t i = 2; i < n; i++) {
        //    int index = 0;
        //    while (true) {
        //        res[index] = (res[index] + 1) % 2;
        //        index += i;
        //        if (index + i >= n)
        //            break;
        //    }
        //}
        //res[n - 1] = (res[n - 1] + 1) % 2;
        //int sum = 0;
        //for (const auto& re : res)
        //    sum += re;
        //return sum;
        return sqrt(n + 0.5);
    }
};
int main() {
    Solution S;
    int n = 4;
    auto res = S.bulbSwitch(n);
    cout << res << endl;
    return 0;
}