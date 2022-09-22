#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> pieceMap;
        for (int i = 0; i < pieces.size(); ++i) {
            pieceMap[pieces[i][0]] = i;
        }
        int p = 0;
        while (p < arr.size()) {
            if (pieceMap.count(arr[p]) == 0) return false;
            int ind = pieceMap[arr[p]];
            for (int i = 0; i < pieces[ind].size(); ++i, ++p) {
                if (pieces[ind][i] != arr[p]) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution S;
    vector<int> arr = { 91,4,64,78 };
    vector<vector<int>> pieces = { {78}, {4, 64}, {91} };
    auto res = S.canFormArray(arr, pieces);
    cout << res << endl;
}