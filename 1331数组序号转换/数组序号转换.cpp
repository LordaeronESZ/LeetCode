#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> seqMap;
        auto arrCpy = arr;
        sort(arr.begin(), arr.end());
        int seq = 1;
        for (int i = 0; i < n; ++i) {
            seqMap[arr[i]] = seq++;
            if (i + 1< n && arr[i] == arr[i + 1]) {
                --seq;
            }
        }
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = seqMap[arrCpy[i]];
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> arr = { 37,12,28,9,100,56,80,5,12 };
    auto res = S.arrayRankTransform(arr);
    for (const auto& re : res) {
        cout << re << " ";
    }
}