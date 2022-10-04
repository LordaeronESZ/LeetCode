#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.emplace(s[i]);
            }
            else {
                if (st.empty() || st.top() == ')') {
                    ++res;
                }
                else {
                    st.pop();
                }
            }
        }
        while (!st.empty()) {
            ++res;
            st.pop();
        }
        return res;
    }
};

int main() {
    Solution S;
    string s = "()))((";
    auto res = S.minAddToMakeValid(s);
    cout << res << endl;
}