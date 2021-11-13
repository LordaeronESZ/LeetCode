#include<iostream>
using namespace std;
class Solution {
private:
    int pick = 200;
public:
    int guess(int num) {
        if (pick < num)
            return -1;
        else if (pick == num)
            return 0;
        else
            return 1;
    }
    int guessNumber(int n) {
        while (true) {
            if (!guess(n))
                return n;
            else if (guess(n) == -1)
                n--;
            else
                n++;
        }
    }
};
int main() {
    Solution S;
    int n = 7;
    auto res = S.guessNumber(n);
    cout << res << endl;
    return 0;
}