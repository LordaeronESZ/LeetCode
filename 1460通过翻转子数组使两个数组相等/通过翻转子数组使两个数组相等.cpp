#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < target.size(); ++i) {
            ++numMap[target[i]];
        }
        for (int i = 0; i < arr.size(); ++i) {
            --numMap[arr[i]];
            if (numMap[arr[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution S;
    vector<int> target = { 3,7,9 };
    vector<int> arr = { 3,7,11 };
    auto res = S.canBeEqual(arr, target);
    cout << res << endl;
}