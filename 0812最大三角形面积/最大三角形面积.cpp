#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    inline double getArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = DBL_MIN;
        for (int i = 0; i < points.size(); ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < points.size(); ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                for (int k = j + 1; k < points.size(); ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    double curArea = getArea(x1, y1, x2, y2, x3, y3);
                    res = max(res, curArea);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> points = { {0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0} };
    auto res = S.largestTriangleArea(points);
    cout << res << endl;
}