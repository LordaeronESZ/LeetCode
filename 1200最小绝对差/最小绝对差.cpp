#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int minDiff = INT32_MAX;
        for (int i = 0; i < arr.size() - 1; ++i) {
            int diff = arr[i + 1] - arr[i];
            if (diff < minDiff) {
                res.clear();
                res.push_back({ arr[i], arr[i + 1] });
                minDiff = diff;
            }
            else if (diff == minDiff) {
                res.push_back({ arr[i], arr[i + 1] });
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> arr = { 4,2,1,3 };
    auto res = S.minimumAbsDifference(arr);
    for (const auto& re : res) {
        cout << re[0] << " " << re[1] << endl;
    }
}