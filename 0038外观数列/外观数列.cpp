#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string first = "1";
        int count = 0;
        string new_str, update_str;
        for (int i = 1; i < n; i++) {
            for (auto f : first) {
                if (update_str.empty()) {
                    update_str += f;
                    count++;
                }
                else if (update_str.at(0) == f)
                    count++;
                else {
                    update_str.insert(update_str.begin(), char(count + '0'));
                    new_str += update_str;
                    update_str.clear();
                    count = 0;
                    update_str += f;
                    count++;
                }
            }
            if (!update_str.empty()) {
                update_str.insert(update_str.begin(), char(count + '0'));
                new_str += update_str;
                update_str.clear();
                count = 0;
            }
            first = new_str;
            new_str.clear();
        }
        return first;
    }
};
int main() {
    Solution S;
    for (int i = 1; i <= 10; i++)
        cout << S.countAndSay(i) << endl;
    //cout << S.countAndSay(4) << endl;
    return 0;
}