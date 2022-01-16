#include<iostream>
using namespace std;
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res = 0;
        while (target > 1) {
            if (maxDoubles > 0) {
                if (target % 2) {
                    target--;
                    target /= 2;
                    maxDoubles--;
                    res += 2;
                }
                else {
                    target /= 2;
                    maxDoubles--;
                    res++;
                }
            }
            else {
                res += target - 1;
                target = 1;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    int target = 19, maxDoubles = 2;
    auto res = S.minMoves(19, 2);
    cout << res << endl;
    return 0;
}