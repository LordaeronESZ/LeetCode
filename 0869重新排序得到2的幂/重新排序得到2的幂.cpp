#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> list;
        while (n) {
            list.emplace_back(n % 10);
            n /= 10;
        }
        sort(list.begin(), list.end());
        int val = 1;
        vector<int> list2;
        while (val <= 10e9) {
            int tempVal = val;
            while (tempVal) {
                list2.emplace_back(tempVal % 10);
                tempVal /= 10;
            }
            sort(list2.begin(), list2.end());
            if (list2.size() > list.size())
                break;
            else if (list == list2)
                return true;
            val *= 2;
            list2.clear();
        }
        return false;
    }
};
int main() {
    Solution S;
    int n = 46;
    auto res = S.reorderedPowerOf2(n);
    cout << res << endl;
    return 0;
}