#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cntMap;
        int res = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            ++cntMap[fruits[i]];
            while (cntMap.size() > 2) {
                --cntMap[fruits[start]];
                if (cntMap[fruits[start]] == 0) {
                    cntMap.erase(fruits[start]);
                }
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> fruits = { 3,3,3,1,2,1,1,2,3,3,4 };
    auto res = S.totalFruit(fruits);
    cout << res << endl;
}