#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1) {
            return c0[1] < c1[1];
            });
        priority_queue<int> q;
        // 优先队列中所有课程的总时间
        int total = 0;
        for (const auto& course : courses) {
            int ti = course[0], di = course[1];
            if (total + ti <= di) {
                total += ti;
                q.push(ti);
            }
            else if (!q.empty() && q.top() > ti) {
                total -= q.top() - ti;
                q.pop();
                q.push(ti);
            }
        }

        return q.size();
    }
};
int main() {
    Solution S;
    vector<vector<int>> courses = { {5,5},{4,6},{2,6} };
    auto res = S.scheduleCourse(courses);
    cout << res << endl;
    return 0;
}