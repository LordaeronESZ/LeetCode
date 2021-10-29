#include<iostream>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z > 0) {
            if (z % 2)
                res++;
            z /= 2;
        }
        return res;
    }
};
int main() {
    Solution S;
    int x = 1, y = 4;
    auto res = S.hammingDistance(x, y);
    cout << res << endl;
    return 0;
}