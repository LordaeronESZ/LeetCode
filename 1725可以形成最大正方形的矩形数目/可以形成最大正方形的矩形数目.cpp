#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int res = 0, maxRec = 0;
        for (const auto& rectangle : rectangles) {
            int rectEdge = min(rectangle[0], rectangle[1]);
            if (maxRec < rectEdge) {
                res = 1;
                maxRec = rectEdge;
            }
            else if (maxRec == rectEdge) {
                res++;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> rectangles = { {5,8},{3,9},{5,12},{16,5} };
    auto res = S.countGoodRectangles(rectangles);
    cout << res << endl;
    return 0;
}