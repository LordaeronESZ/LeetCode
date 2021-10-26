#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
// 常规解法
//class Solution {
//public:
//    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> res(nums1.size(), -1);
//        for (size_t i = 0; i < nums1.size(); i++) {
//            bool isBack = false;
//            for (size_t j = 0; j < nums2.size(); j++) {
//                if (nums2[j] == nums1[i])
//                    isBack = true;
//                if (isBack && nums2[j] > nums1[i]) {
//                    res[i] = nums2[j];
//                    break;
//                }
//            }
//        }
//        return res;
//    }
//};
// HashMap + Stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> S;
        unordered_map<int, int> numsMap;
        for (size_t i = 0; i < nums2.size(); i++) {
            if (!i) {
                S.push(nums2[i]);
                continue;
            }
            while (!S.empty() && nums2[i] > S.top()) {
                numsMap.insert(make_pair(S.top(), nums2[i]));
                S.pop();
            }
            S.push(nums2[i]);
        }
        for (const auto& num1 : nums1) {
            if (numsMap.count(num1))
                res.emplace_back(numsMap[num1]);
            else
                res.emplace_back(-1);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };
    auto res = S.nextGreaterElement(nums1, nums2);
    for (const auto& re : res)
        cout << re << " ";
    return 0;
}