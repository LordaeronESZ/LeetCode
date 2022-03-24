#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1} };
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0, cnt = 0;
                for (const auto& dir : dirs) {
                    int ni = i + dir[0], nj = j + dir[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        sum += img[ni][nj];
                        ++cnt;
                    }
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> img = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13}, {14, 15, 16}};
    auto res = S.imageSmoother(img);
    for (const auto& re : res) {
        for (const auto& r : re) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}