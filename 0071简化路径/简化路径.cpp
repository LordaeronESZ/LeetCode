#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string res;
        vector<string> pathList;
        int beginIndex = 0;
        for (int i = 1; i < path.size(); i++) {
            if (path[i] == '/') {
                string tempStr = path.substr(beginIndex, i - beginIndex);
                beginIndex = i;
                if (tempStr == "/." || tempStr == "/") {
                    continue;
                }
                else if (tempStr == "/..") {
                    if(!pathList.empty())
                        pathList.pop_back();
                }
                else {
                    pathList.emplace_back(tempStr);
                }
            }
            else if (i == path.size() - 1) {
                string tempStr = path.substr(beginIndex, i - beginIndex + 1);
                if (tempStr == "/." || tempStr == "/") {
                    continue;
                }
                else if (tempStr == "/..") {
                    if (!pathList.empty())
                        pathList.pop_back();
                }
                else {
                    pathList.emplace_back(tempStr);
                }
            }
        }
        for (const auto& str : pathList) {
            res += str;
        }
        return res.empty() ? "/" : res;
    }
};
int main() {
    Solution S;
    string path = "/a//b////c/d//././/..";
    string path2 = "/.";
    auto res = S.simplifyPath(path2);
    cout << res << endl;
    return 0;
}