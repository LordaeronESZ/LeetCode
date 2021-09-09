#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!m) {
            nums1 = nums2;
            return;
        }
        int p = m - 1, q = n - 1;
        int r = m + n - 1;
        while (q >= 0 && p >= 0) {
            if (nums2[q] >= nums1[p]) {
                nums1[r] = nums2[q];
                q--;
            }
            else {
                swap(nums1[r], nums1[p]);
                p--;
            }
            r--;
        }
        if (p < 0) {
            while(q >= 0 && r >= 0)
                nums1[r--] = nums2[q--];
        }
    }
};
int main() {
    vector<int> nums1 = { 4,5,6,0,0,0 };
    vector<int> nums2 = { 1,2,3 };
    int m = 3, n = 3;
    Solution S;
    S.merge(nums1, m, nums2, n);
    for (auto n : nums1)
        cout << n << " ";
    return 0;
}