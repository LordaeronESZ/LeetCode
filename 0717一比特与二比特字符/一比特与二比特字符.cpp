#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (auto it = bits.begin(); it <= bits.end();) {
            if (it == bits.end())
                return false;
            else if (it == bits.end() - 1)
                return true;
            if (*it == 1)
                it += 2;
            else
                it++;
        }
        return true;
    }
};
int main() {
    Solution S;
    vector<int> bits = { 1,0,0 };
    auto res = S.isOneBitCharacter(bits);
    cout << res << endl;
    return 0;
}