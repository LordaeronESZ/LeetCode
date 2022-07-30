#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
private:
    int getDistance(vector<int>& p1, vector<int>& p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> disSet;
        vector<vector<int>> p = { p1, p2, p3, p4 };
        for (int i = 0; i < p.size(); ++i) {
            for (int j = i + 1; j < p.size(); ++j) {
                int dis = getDistance(p[i], p[j]);
                if (!dis) {
                    return false;
                }
                disSet.emplace(dis);
            }
        }
        return disSet.size() == 2;
    }
};

int main() {
    Solution S;
    vector<int> p1 = { 1,0 };
    vector<int> p2 = { -1,0 };
    vector<int> p3 = { 0,1 };
    vector<int> p4 = { 0,-1 };
    auto res = S.validSquare(p1, p2, p3, p4);
    cout << res << endl;
}