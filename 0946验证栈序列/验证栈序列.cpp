#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushed.size()) {
            if (!st.empty() && st.top() == popped[j]) {
                st.pop();
                ++j;
            }
            else {
                st.emplace(pushed[i++]);
            }
        }
        while (!st.empty() && j < popped.size()) {
            if (st.top() == popped[j]) {
                st.pop();
                ++j;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution S;
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> popped = { 4,3,5,1,2 };
    auto res = S.validateStackSequences(pushed, popped);
    cout << res << endl;
}