#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int num = candyType.size() / 2;
        int cur_num = 1;
        sort(candyType.begin(), candyType.end());
        for (size_t i = 1; i < candyType.size(); i++) {
            if (cur_num >= num)
                return num;
            if (candyType[i] != candyType[i - 1])
                cur_num++;
        }
        return cur_num;
    }
};
int main() {
    Solution S;
    vector<int> candyType = { 1,1,2,2,3,3 };
    auto res = S.distributeCandies(candyType);
    cout << res << endl;
    return 0;
}