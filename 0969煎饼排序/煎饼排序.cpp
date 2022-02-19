#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            auto maxValIt = max_element(arr.begin(), arr.end() - i);
            if (maxValIt == arr.end() - i)
                continue;
            reverse(arr.begin(), maxValIt + 1);
            reverse(arr.begin(), arr.end() - i);
            res.emplace_back(maxValIt + 1 - arr.begin());
            res.emplace_back(arr.end() - arr.begin() - i);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> arr = { 3,2,4,1 };
    auto res = S.pancakeSort(arr);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}