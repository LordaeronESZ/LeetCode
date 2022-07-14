#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class WordFilter {
private:
    map<string, int> wordMap;
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string prefix, suff;
            for (int j = 1; j <= words[i].size(); ++j) {
                prefix = words[i].substr(0, j);
                for (int k = 0; k < words[i].size(); ++k) {
                    suff = words[i].substr(k);
                    string ps = prefix + ":" + suff;
                    wordMap[ps] = i;
                }
            }
        }
    }

    int f(string pref, string suff) {
        string target = pref + ":" + suff;
        if (wordMap.count(target))
            return wordMap[target];
        else
            return -1;
    }
};

int main() {
    vector<string> words = { "apple" };
    WordFilter wordFilter(words);
    cout << wordFilter.f("a", "e") << endl; // 返回 0 ，因为下标为 0 的单词：前缀 prefix = "a" 且 后缀 suff = "e" 。
}