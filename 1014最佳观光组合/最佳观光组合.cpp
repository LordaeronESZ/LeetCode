#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //拆分成values[i] + i和values[j] - j两部分
        //先求values[i] + i最大值maxVal，再同时加上values[j] - j更新最大值
        int res = INT32_MIN;
        int maxVal = values[0];
        for (int j = 1; j < values.size(); j++) {
            res = max(res, maxVal + values[j] - j);
            maxVal = max(maxVal, values[j] + j);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> values = { 8,1,5,2,6 };
    auto res = S.maxScoreSightseeingPair(values);
    cout << res << endl;
    return 0;
}