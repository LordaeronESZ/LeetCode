#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, maxVal = 0;
        for (int i = 0; i < arr.size(); ++i) {
            maxVal = max(maxVal, arr[i]);
            res += maxVal == i;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> arr = { 1,2,0,3 };
    auto res = S.maxChunksToSorted(arr);
    cout << res << endl;
}