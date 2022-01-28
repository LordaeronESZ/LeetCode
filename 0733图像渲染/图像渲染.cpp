#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oriColor) {
        int m = image.size(), n = image[0].size();
        image[sr][sc] = newColor;
        if (sr - 1 >= 0 && image[sr - 1][sc] == oriColor)
            floodFill(image, sr - 1, sc, newColor);
        if (sr + 1 < m && image[sr + 1][sc] == oriColor)
            floodFill(image, sr + 1, sc, newColor);
        if (sc - 1 >= 0 && image[sr][sc - 1] == oriColor)
            floodFill(image, sr, sc - 1, newColor);
        if (sc + 1 < n && image[sr][sc + 1] == oriColor)
            floodFill(image, sr, sc + 1, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oriColor = image[sr][sc];
        if (oriColor != newColor)
            dfs(image, sr, sc, newColor, oriColor);
        return image;
    }
};
int main() {
    Solution S;
    vector<vector<int>> image = { {0,0,0},{0,0,0} };
    auto res = S.floodFill(image, 0, 0, 2);
    for (const auto& re : res) {
        for (const auto& r : re) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}