#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    //先排序得到唯一的映射key，再向key对应的value中加入str
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> dic;
        vector<vector<string>> res;
        for (auto str : strs) {
            auto temp_str = str;
            sort(temp_str.begin(), temp_str.end());
            dic[temp_str].push_back(str);
        }
        for (auto d : dic)
            res.push_back(d.second);
        return res;
    }
};
int main() {
    Solution S;
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    auto res = S.groupAnagrams(strs);
    for (auto re : res) {
        for (auto r : re)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}