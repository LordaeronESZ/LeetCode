#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> arrMap;
        int res = INT32_MIN;
        for (const auto& a : arr) {
            arrMap[a] = arrMap[a - difference] ? arrMap[a - difference] + 1 : 1;
            if (arrMap[a] > res)
                res = arrMap[a];
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> arr = { 1,5,7,8,5,3,4,2,1 };
    int difference = -2;
    auto res = S.longestSubsequence(arr, difference);
    cout << res << endl;
    return 0;
}