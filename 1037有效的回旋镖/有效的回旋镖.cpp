#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        vector<int> v1 = { points[1][0] - points[0][0], points[1][1] - points[0][1] };
        vector<int> v2 = { points[2][0] - points[0][0], points[2][1] - points[0][1] };
        return v1[0] * v2[1] - v1[1] * v2[0] != 0;
    }
};

int main() {
    Solution S;
    vector<vector<int>> points = { {1,0} ,{2,0},{0,0} };
    auto res = S.isBoomerang(points);
    cout << res << endl;
}