#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibVec = { 1,1 };
        while (fibVec.back() < k) {
            int n = fibVec.size();
            int next = fibVec[n - 1] + fibVec[n - 2];
            fibVec.emplace_back(next);
        }
        int res = 0;
        for (int i = fibVec.size() - 1; i >= 0; i--) {
            if (fibVec[i] <= k) {
                k -= fibVec[i];
                res++;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    int k = 19;
    auto res = S.findMinFibonacciNumbers(k);
    cout << res << endl;
    return 0;
}