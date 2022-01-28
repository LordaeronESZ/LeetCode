#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0, n = properties.size();
        sort(properties.begin(), properties.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] > p2[0];
            });
        int maxDef = INT32_MIN;
        for (const auto& property : properties) {
            if (property[1] < maxDef)
                res++;
            else
                maxDef = property[1];
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> properties = { {1,5},{10,4},{4,3} };
    auto res = S.numberOfWeakCharacters(properties);
    cout << res << endl;
    return 0;
}