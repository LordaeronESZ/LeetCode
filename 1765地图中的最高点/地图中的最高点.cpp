#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
private:
    vector<vector<int>> dirList = { {-1,0},{1,0},{0,-1},{0,1} };
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> coordQ;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    res[i][j] = 0;
                    coordQ.push(make_pair(i, j));
                }
            }
        }
        while (!coordQ.empty()) {
            auto coord = coordQ.front();
            for (const auto& dir : dirList) {
                int x = coord.first + dir[0], y = coord.second + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && res[x][y] == -1) {
                    res[x][y] = res[coord.first][coord.second] + 1;
                    coordQ.push(make_pair(x, y));
                }
            }
            coordQ.pop();
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> isWater = { {0,0,1},{1,0,0},{0,0,0} };
    auto res = S.highestPeak(isWater);
    for (const auto& re : res) {
        for (const auto& r : re) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}