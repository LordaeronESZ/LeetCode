#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while (k--) {
            if (left <= -1) {
                ++right;
            }
            else if (right >= arr.size()) {
                --left;
            }
            else {
                int sub1 = abs(arr[left] - x);
                int sub2 = abs(arr[right] - x);
                if (sub1 <= sub2) {
                    --left;
                }
                else {
                    ++right;
                }
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};

int main() {
    Solution S;
    vector<int> arr = { 3,5,8,10 };
    int k = 2, x = 15;
    auto res = S.findClosestElements(arr, k, x);
    for (const auto& re : res) {
        cout << re << " ";
    }
}