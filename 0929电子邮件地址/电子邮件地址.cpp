#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int res = 0;
        unordered_set<string> emailSet;
        for (const auto& email : emails) {
            string temp;
            int ind = 0;
            while (ind < email.size()) {
                if (email[ind] == '@') {
                    temp += email.substr(ind);
                    break;
                }
                else if (email[ind] == '+') {
                    while (email[++ind] != '@');
                    continue;
                }
                else if (email[ind] != '.') {
                    temp += email[ind];
                }
                ++ind;
            }
            if (emailSet.count(temp) == 0) {
                ++res;
                emailSet.emplace(temp);
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<string> emails = { "test.email+alex@leetcode.com", "test.email@leetcode.com" };
    auto res = S.numUniqueEmails(emails);
    cout << res << endl;
}