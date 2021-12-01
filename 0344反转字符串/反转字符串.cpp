#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int p = 0, q = s.size() - 1;
        while (p < q) {
            swap(s[p], s[q]);
            p++;
            q--;
        }
    }
};
int main() {
    Solution S;
    vector<char> s = { 'h','e','l','l','o' };
    S.reverseString(s);
    for (const auto& ch : s)
        cout << ch << " ";
    return 0;
}