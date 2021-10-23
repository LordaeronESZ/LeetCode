#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0, count = 0;
        for (const auto& num : nums) {
            if (count == 0) {
                element = num;
                count++;
            }
            else {
                if (element == num)
                    count++;
                else
                    count--;
            }
        }
        return element;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 2,2,1,1,1,2,2 };
    auto res = S.majorityElement(nums);
    cout << res << endl;
    return 0;
}