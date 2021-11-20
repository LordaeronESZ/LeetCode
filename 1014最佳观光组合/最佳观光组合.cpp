#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //��ֳ�values[i] + i��values[j] - j������
        //����values[i] + i���ֵmaxVal����ͬʱ����values[j] - j�������ֵ
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