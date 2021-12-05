#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransomMap;
        for (const auto& ch : magazine) {
            ransomMap[ch]++;
        }
        for (const auto& ch : ransomNote) {
            ransomMap[ch]--;
            if (ransomMap[ch] < 0)
                return false;
        }
        return true;
    }
};
int main() {
    Solution S;
    string ransomNote = "abccdde";
    string magazine = "abbccddefg";
    auto res = S.canConstruct(ransomNote, magazine);
    cout << res << endl;
    return 0;
}