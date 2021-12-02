#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res;
        unordered_map<int, int> scoreMap;
        vector<int> sortedScore(score);
        sort(sortedScore.begin(), sortedScore.end(), [](int a, int b) {return a > b; });
        for (int i = 0; i < sortedScore.size(); i++) {
            scoreMap[sortedScore[i]] = i + 1;
        }
        for (int i = 0; i < score.size(); i++) {
            switch (scoreMap[score[i]])
            {
            case 1:
                res.emplace_back("Gold Medal"); break;
            case 2:
                res.emplace_back("Silver Medal"); break;
            case 3:
                res.emplace_back("Bronze Medal"); break;
            default:
                res.emplace_back(to_string(scoreMap[score[i]])); break;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> score = { 10,3,8,9,4 };
    auto res = S.findRelativeRanks(score);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}