#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> numCnt;
        for (const auto& num : arr) {
            ++numCnt[num];
        }
        sort(arr.begin(), arr.end(), [](const int& num1, const int& num2) {
            return abs(num1) < abs(num2);
        });
        for (const auto& num : arr) {
            if (numCnt[num]) {
                --numCnt[num];
                --numCnt[num * 2];
                if (numCnt[num] < 0 || numCnt[num * 2] < 0)
                    return false;
            }
        }
        return true;
    }
};
int main() {
    Solution S;
    vector<int> arr = { 4,-2,2,-3 };
    auto res = S.canReorderDoubled(arr);
    cout << res << endl;
}