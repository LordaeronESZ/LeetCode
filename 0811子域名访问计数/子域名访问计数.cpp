#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domainMap;
        for (int i = 0; i < cpdomains.size(); ++i) {
            string domainName;
            int cnt = 0;
            for (int j = 0; j < cpdomains[i].size(); ++j) {
                if (cpdomains[i][j] == ' ') {
                    cnt = stoi(cpdomains[i].substr(0, j));
                    domainName = cpdomains[i].substr(j + 1);
                }
            }
            domainMap[domainName] += cnt;
            for (int j = 0; j < domainName.size(); ++j) {
                if (domainName[j] == '.') {
                    domainMap[domainName.substr(j + 1)] += cnt;
                }
            }
        }
        vector<string> res;
        for (const auto& domainCnt : domainMap) {
            string dc = to_string(domainCnt.second) + " " + domainCnt.first;
            res.emplace_back(dc);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<string> cpdomains = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
    auto res = S.subdomainVisits(cpdomains);
    for (const auto& re : res) {
        cout << re << endl;
    }
}