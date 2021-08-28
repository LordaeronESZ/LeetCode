#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> dic;
        vector<int> result;
        for (auto i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            int j;
            for (j = 0; j < dic.size(); j++)
            {
                if (temp == nums[j]) {
                    result.push_back(j);
                    result.push_back(i);
                    return result;
                }
            }
            if (j == dic.size()) {
                dic.push_back(temp);
            }
        }
        return result;
    }
};
int main() {
    Solution S;
    vector<int> nums;
    int target, temp;
    while (cin >> temp)
    {
        nums.push_back(temp);
        if (cin.get() == '\n')
            break;
    }
    cin >> target;
    vector<int> result = S.twoSum(nums, target);
    for (auto it = result.begin(); it < result.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}