#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string r;
        if (digits == "")
            return res;
        unordered_map<char, string> num_dic = { {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
            {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
        Func(res, num_dic, digits, 0, r);
        return res;
    }
    void Func(vector<string>& res, unordered_map<char, string> num_dic, string digits, int index, string& r) {
        if (index == digits.size())
            res.push_back(r);
        else {
            char d = digits[index];
            string letters = num_dic[d];
            for (auto l : letters) {
                r.push_back(l);
                Func(res, num_dic, digits, index + 1, r);
                r.pop_back();
            }
        }
    }
};
int main() {
    string digits = "23";
    Solution S;
    vector<string> res = S.letterCombinations(digits);
    for (auto r : res)
        cout << r << endl;
    return 0;
}