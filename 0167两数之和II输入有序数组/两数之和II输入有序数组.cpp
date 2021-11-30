#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++) {
            int l = i + 1, r = numbers.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (numbers[mid] == target - numbers[i])
                    return { i + 1,mid + 1 };
                else if (numbers[mid] > target - numbers[i])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return {};
    }
};
int main() {
    Solution S;
    vector<int> numbers = { 2,7,11,15 };
    int target = 9;
    auto res = S.twoSum(numbers, target);
    for (const auto& re : res)
        cout << re << " ";
    return 0;
}