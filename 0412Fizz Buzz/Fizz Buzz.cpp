#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0)
                res.emplace_back("FizzBuzz");
            else if (i % 3 == 0)
                res.emplace_back("Fizz");
            else if (i % 5 == 0)
                res.emplace_back("Buzz");
            else {
                string temp;
                int num = i;
                while (num > 0) {
                    temp.insert(temp.begin(), num % 10 + '0');
                    num /= 10;
                }
                res.emplace_back(temp);
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 15;
    auto res = S.fizzBuzz(n);
    for (auto const& r : res)
        cout << r << endl;
    return 0;
}