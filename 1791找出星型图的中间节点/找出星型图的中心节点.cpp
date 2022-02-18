#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (edges[0][i] == edges[1][j])
                    return edges[0][i];
            }
        }
        return -1;
    }
};
int main() {
    Solution S;
    vector<vector<int>> edges = { {1,2},{2,3},{4,2} };
    auto res = S.findCenter(edges);
    cout << res << endl;
    return 0;
}