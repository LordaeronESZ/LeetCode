#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        sort(strs.begin(), strs.end());
        auto it1 = strs.front().begin();
        auto it2 = strs.back().begin();
        while (it1 < strs.front().end() && it2 < strs.back().end())
        {
            if (*it1 == *it2)
                res += *it1;
            else
                break;
            it1++;
            it2++;
        }
        return res;
    }
};
int main() {
    vector<string> strs;
    Solution S;
    while (true)
    {
        string temp;
        cin >> temp;
        if (temp == "exit")
            break;
        strs.push_back(temp);
    }
    string res = S.longestCommonPrefix(strs);
    cout << res << endl;
    return 0;
}