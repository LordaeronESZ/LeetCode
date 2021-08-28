#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string result(s.size(),' ');
        int flag = -1, row = 0, column = 0;
        for (int i = 0; i < s.size(); i++)
        {
            //向下移动
            if (flag > 0) {
                result[row * numRows + column] = s[i];
            }
            //向上移动 
            else {
                result[row * numRows + column] = s[i];
                if(row != 0 && row != numRows - 1)
                    column++;
            }
            //到达底边
            if (row == 0 || row == numRows - 1) {
                flag *= -1;
            }
            row += flag;
        }
        return result;
    }
};
int main() {
    Solution S;
    string s;
    cin >> s;
    string result = S.convert(s, 3);
    cout << result << endl;
    return 0;
}