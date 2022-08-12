#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> groupMap;
        for (int i = 0; i < groupSizes.size(); ++i) {
            groupMap[groupSizes[i]].emplace_back(i);
        }
        vector<vector<int>> res;
        for (const auto& group : groupMap) {
            vector<int> temp;
            for (int i = 0; i < group.second.size(); ++i) {
                temp.emplace_back(group.second[i]);
                if (temp.size() == group.first) {
                    res.emplace_back(temp);
                    temp.clear();
                }
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> groupSizes = { 2,1,3,3,3,2 };
    auto res = S.groupThePeople(groupSizes);
    for (const auto& re : res) {
        for (const auto& r : re) {
            cout << r << " ";
        }
        cout << endl;
    }
}