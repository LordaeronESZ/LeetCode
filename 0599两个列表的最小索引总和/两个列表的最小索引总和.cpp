#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> strInd;
        for (int i = 0; i < list1.size(); ++i) {
            strInd[list1[i]] = i;
        }
        int best_sum = INT32_MAX;
        for (int i = 0; i < list2.size(); ++i) {
            if (strInd.find(list2[i]) != strInd.end()) {
                int sum = strInd[list2[i]] + i;
                if (sum <= best_sum) {
                    if (sum < best_sum)
                        res.clear();
                    res.emplace_back(list2[i]);
                    best_sum = sum;
                }
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<string> list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    vector<string> list2 = { "KFC", "Shogun", "Burger King" };
    auto res = S.findRestaurant(list1, list2);
    for (const auto& re : res) {
        cout << re << endl;
    }
    return 0;
}