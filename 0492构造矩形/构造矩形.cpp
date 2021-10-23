#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int midValue = static_cast<int>(sqrt(area));
        for (int i = midValue; i <= area; i++) {
            if (area % i == 0 && i >= area / i) {
                return { i, area / i };
            }
        }
        return {};
    }
};
int main() {
    Solution S;
    int area = 6;
    auto res = S.constructRectangle(area);
    cout << res.front() << " " << res.back() << endl;
    return 0;
}