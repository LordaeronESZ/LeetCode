#include<vector>
#include<queue>
#include <iostream>
using namespace std;
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        int i = 1, res = 0;
        Q.push(make_pair(days[0], apples[0]));
        while (!Q.empty()) {
            if (i < apples.size())
                Q.push(make_pair(days[i], apples[i]));
            auto Qtop = Q.top();
            Q.pop();
            Qtop.first -= 1;
            Qtop.second -= 1;
            res++;
            Q.push(Qtop);
            while (!Q.top().first) {
                Q.pop();
            }
            i++;
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> apples = { 1,2,3,5,2 };
    vector<int> days = { 3,2,1,4,2 };
    auto res = S.eatenApples(apples, days);
    cout << res << endl;
    return 0;
}