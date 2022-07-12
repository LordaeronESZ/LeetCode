#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class MagicDictionary {
private:
    unordered_set<string> wordSet;
public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        for (const auto& str : dictionary) {
            wordSet.emplace(str);
        }
    }

    bool search(string searchWord) {
        for (auto& ch : searchWord) {
            char chCpy = ch;
            for (char nc = 'a'; nc <= 'z'; ++nc) {
                if (nc == chCpy)
                    continue;
                ch = nc;
                if (wordSet.count(searchWord))
                    return true;
            }
            ch = chCpy;
        }
        return false;
    }
};

int main() {
    MagicDictionary magicDictionary;
    magicDictionary.buildDict({ "hello", "leetcode" });
    cout << magicDictionary.search("hello") << endl; // 返回 False
    cout << magicDictionary.search("hhllo") << endl; // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
    cout << magicDictionary.search("hell") << endl; // 返回 False
    cout << magicDictionary.search("leetcoded") << endl; // 返回 False
}