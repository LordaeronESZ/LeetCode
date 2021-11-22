#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
class Solution {
private:
    vector<int> oriNums;
    vector<int> curNums;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            oriNums.emplace_back(nums[i]);
            curNums.emplace_back(nums[i]);
        }
    }

    vector<int> reset() {
        curNums = oriNums;
        return curNums;
    }

    vector<int> shuffle() {
        for (int i = 0; i < curNums.size(); i++) {
            int j = i + rand() % (curNums.size() - i);
            swap(curNums[i], curNums[j]);
        }
        return curNums;
    }
};
int main() {
    vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
    Solution* S = new Solution(nums);
    auto res1 = S->shuffle();
    for (int i = 0; i < nums.size(); i++) {
        cout << res1[i] << " ";
    }
    cout << endl;
    auto res2 = S->reset();
    for (int i = 0; i < nums.size(); i++) {
        cout << res2[i] << " ";
    }
    cout << endl;
    auto res3 = S->shuffle();
    for (int i = 0; i < nums.size(); i++) {
        cout << res3[i] << " ";
    }
    cout << endl;
}