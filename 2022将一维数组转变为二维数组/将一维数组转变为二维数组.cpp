#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size())
            return {};
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            vector<int>* temp = new vector<int>();
            for (int j = 0; j < n; j++) {
                temp->emplace_back(original[i * n + j]);
            }
            res.emplace_back(*temp);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> original = { 1,2,3,4 };
    int m = 4, n = 1;
    auto res = S.construct2DArray(original, m, n);
    for (const auto& re : res) {
        for (const auto& r : re) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}