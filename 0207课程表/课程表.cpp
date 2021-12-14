#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& p : prerequisites) {
            edges[p[1]].emplace_back(p[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i])
                traversal(i);
        }
        return valid;
    }
    void traversal(int u) {
        visited[u] = 1;
        for (const auto& v : edges[u]) {
            if (visited[v] == 0) {
                traversal(v);
                if (!valid)
                    return;
            }
            else if(visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }
};
int main() {
    Solution S;
    int numCourses = 2;
    vector<vector<int>> prerequisites = { {0,1},{1,0} };
    auto res = S.canFinish(numCourses, prerequisites);
    cout << res << endl;
    return 0;
}