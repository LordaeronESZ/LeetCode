#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int dltNum = 0.05 * n;
        double sum = 0.0;
        for (int i = dltNum; i < n - dltNum; ++i) {
            sum += arr[i];
        }
        return sum / (n - 2 * dltNum);
    }
};

int main() {
    Solution S;
    vector<int> arr = { 6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4 };
    auto res = S.trimMean(arr);
    cout << res << endl;
}