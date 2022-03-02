#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    const vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };
    void dfs(vector<vector<int>>& image, int iniColor, int newColor, int i, int j) {
        int m = image.size(), n = image[0].size();
        image[i][j] = newColor;
        for (const auto& dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && image[ni][nj] == iniColor && image[ni][nj] != newColor) {
                dfs(image, iniColor, newColor, ni, nj);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, image[sr][sc], newColor, sr, sc);
        return image;
    }
};
int main() {
    Solution S;
    vector<vector<int>> image = { {0,0,0},{0,1,1} };
    int sr = 1, sc = 1, newColor = 1;
    auto res = S.floodFill(image, sr, sc, newColor);
    for (const auto& re : res) {
        for (const auto& r : re)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}