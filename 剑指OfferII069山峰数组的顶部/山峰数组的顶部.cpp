#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        size_t i1, i2;
        for (i1 = 0, i2 = 1; i2 < arr.size();) {
            if (arr[i1] < arr[i2]) {
                i1++;
                i2++;
            }
            else
                return i1;
        }
        return i1;
    }
};
int main() {
    Solution S;
    vector<int> arr = { 1,3,5,4,2 };
    auto res = S.peakIndexInMountainArray(arr);
    cout << res << endl;
    return 0;
}