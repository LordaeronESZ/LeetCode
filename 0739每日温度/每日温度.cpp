#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> indStack;
        for (int i = 0; i < n; i++) {
            while (!indStack.empty() && temperatures[i] > temperatures[indStack.top()]) {
                int ind = indStack.top();
                indStack.pop();
                res[ind] = i - ind;
            }
            indStack.emplace(i);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> temperatures = { 73,74,75,71,69,72,76,73 };
    auto res = S.dailyTemperatures(temperatures);
    for (const auto& re : res)
        cout << re << " ";
    return 0;
}