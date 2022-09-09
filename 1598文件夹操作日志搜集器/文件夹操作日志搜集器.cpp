#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (int i = 0; i < logs.size(); ++i) {
            if (logs[i][0] == '.' && logs[i][1] == '.') {
                if (res > 0) {
                    --res;
                }
            }
            else if (logs[i][0] != '.') {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<string> logs = { "d1/","d2/","./","d3/","../","d31/" };
    auto res = S.minOperations(logs);
    cout << res << endl;
}