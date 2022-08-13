#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        auto arrCpy = arr;
        sort(arrCpy.begin(), arrCpy.end());
        long long sum1 = 0, sum2 = 0;
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum1 += arr[i];
            sum2 += arrCpy[i];
            res += sum1 == sum2;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> arr = { 1,1,0,0,1 };
    auto res = S.maxChunksToSorted(arr);
    cout << res << endl;
}