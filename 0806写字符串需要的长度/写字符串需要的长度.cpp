#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int curWidth = 0, lineCnt = 1;
        for (const auto& chr : s) {
            int chrWidth = widths[chr - 'a'];
            if (curWidth + chrWidth <= 100) {
                curWidth += chrWidth;
            }
            else {
                ++lineCnt;
                curWidth = chrWidth;
            }
        }
        return { lineCnt, curWidth };
    }
};
int main() {
    Solution S;
    vector<int> widths = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    string s = "bbbcccdddaaa";
    auto res = S.numberOfLines(widths, s);
    cout << res[0] << " " << res[1] << endl;
}