#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int res = 0;
        unordered_map<int, int> indMap;
        for (int i = 0; i < arr.size(); ++i) {
            indMap[arr[i]] = i;
        }
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                int num1 = arr[i], num2 = arr[j], cnt = 2;
                int sum = num1 + num2;
                while (indMap.count(sum)) {
                    ++cnt;
                    num1 = num2;
                    num2 = sum;
                    sum = num1 + num2;
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> arr = { 1,2,3,4,5,6,7,8 };
    auto res = S.lenLongestFibSubseq(arr);
    cout << res << endl;
}