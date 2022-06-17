#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 0) {
                arr.emplace(arr.begin() + i++, 0);
                arr.pop_back();
            }
        }
    }
};

int main() {
    Solution S;
    vector<int> arr = { 1,0,2,3,0,4,5,0 };
    S.duplicateZeros(arr);
    for (const auto& val : arr) {
        cout << val << " ";
    }
}