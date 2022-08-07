#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int,int>> st;
        vector<int> res(n, 0);

        for (int i = 0; i < logs.size(); ++i) {
            int p = logs[i].find_first_of(':');
            int q = logs[i].find_last_of(':');
            
            int id = stoi(logs[i].substr(0, p));
            string status = logs[i].substr(p + 1, q - p - 1);
            int time = stoi(logs[i].substr(q + 1));
            
            if (status == "start") {
                if (!st.empty()) {
                    res[st.top().first] += time - st.top().second;
                    st.top().second = time;
                }
                st.emplace(id, time);
            }
            else {
                auto t = st.top();
                st.pop();
                res[t.first] += time - t.second + 1;
                if (!st.empty()) {
                    st.top().second = time + 1;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution S;
    int n = 2;
    vector<string> logs = { "0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7" };
    auto res = S.exclusiveTime(n, logs);
    for (const auto& re : res) {
        cout << re << " ";
    }
}