#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        double result;
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while (it1 < nums1.end() && it2 < nums2.end()) {
            if (*it1 < *it2) {
                merge.push_back(*it1);
                it1++;
            }
            else {
                merge.push_back(*it2);
                it2++;
            }
        }
        while (it1 < nums1.end()) {
            merge.push_back(*it1);
            it1++;
        }
        while (it2 < nums2.end()) {
            merge.push_back(*it2);
            it2++;
        }
        //合并数组大小为奇数
        if (merge.size() % 2) {
            result = merge[merge.size() / 2];
        }
        //合并数组大小为偶数
        else {
            result = (merge[merge.size() / 2] + merge[merge.size() / 2 - 1]) / 2.0;
        }
        return result;
    }
};
int main() {
    vector<int> nums1;
    vector<int> nums2;
    int temp;
    while (cin >> temp) {
        nums1.push_back(temp);
        if (cin.get() == '\n')
            break;
    }
    while (cin >> temp) {
        nums2.push_back(temp);
        if (cin.get() == '\n')
            break;
    }
    Solution S;
    double result = S.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}