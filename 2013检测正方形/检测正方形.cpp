#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;
    DetectSquares() {

    }

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[y][x]++;
    }

    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        if (!cnt.count(y)) {
            return 0;
        }
        unordered_map<int, int>& yCnt = cnt[y];
        for (auto& c : cnt) {
            if (c.first != y) {
                int d = c.first - y;
                res += (c.second.count(x) ? c.second[x] : 0) * (yCnt.count(x + d) ? yCnt[x + d] : 0) *
                    (c.second.count(x + d) ? c.second[x + d] : 0);
                res += (c.second.count(x) ? c.second[x] : 0) * (yCnt.count(x - d) ? yCnt[x - d] : 0) *
                    (c.second.count(x - d) ? c.second[x - d] : 0);
            }
        }
        return res;
    }
};
int main() {
    DetectSquares* DS = new DetectSquares();
    DS->add({ 3,10 });
    DS->add({ 3,10 });
    DS->add({ 11,2 });
    DS->add({ 3,2 });
    DS->add({ 3,2 });
    DS->add({ 3,2 });
    cout << DS->count({ 11,10 });
    return 0;
}