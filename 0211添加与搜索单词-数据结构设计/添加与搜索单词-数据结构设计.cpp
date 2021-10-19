#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class WordDictionary {
private:
    map<int, vector<string>> dictionary;
public:
    WordDictionary() {
        
    }

    void addWord(string word) {
        dictionary[word.size()].emplace_back(word);
    }

    bool search(string word) {
        vector<string>& token = dictionary[word.size()];
        for (const auto& str : token) {
            auto w = word.cbegin();
            for (const auto& ch : str) {
                if (*w != '.' && *w != ch)
                    break;
                w++;
            }
            if (w == word.cend())
                return true;
        }
        return false;
    }
};
int main() {
    WordDictionary* wordDictionary = new WordDictionary();
    wordDictionary->addWord("at");
    wordDictionary->addWord("and");
    wordDictionary->addWord("an");
    wordDictionary->addWord("add");
    cout << wordDictionary->search("a") << endl;
    cout << wordDictionary->search(".at") << endl;
    wordDictionary->addWord("bat");
    cout << wordDictionary->search(".at") << endl;
    cout << wordDictionary->search("an.") << endl;
    cout << wordDictionary->search("a.d.") << endl;
    cout << wordDictionary->search("b.") << endl;
    cout << wordDictionary->search("a.d") << endl;
    cout << wordDictionary->search(".") << endl;
    return 0;
}