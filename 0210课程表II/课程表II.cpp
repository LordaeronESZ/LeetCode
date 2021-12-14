#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> order;
    bool valid = true;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& p : prerequisites) {
            edges[p[1]].emplace_back(p[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i])
                traversal(i);
        }
        if (!valid)
            return {};
        reverse(order.begin(), order.end());
        return order;
    }
    void traversal(int u) {
        visited[u] = 1;
        for (const auto& v : edges[u]) {
            if (visited[v] == 0) {
                traversal(v);
                if (!valid)
                    return;
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
        order.emplace_back(u);
    }
};
int main() {
    Solution S;
    int numCourses = 4;
    vector<vector<int>> prerequisites = { {1,0},{2,0},{3,1},{3,2} };
    auto res = S.findOrder(numCourses, prerequisites);
    for (const auto& re : res)
        cout << re << " ";
    return 0;
}