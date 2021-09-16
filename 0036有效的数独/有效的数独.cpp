#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> dic_row(10, vector<bool>(10, false));
        vector<vector<bool>> dic_col(10, vector<bool>(10, false));
        vector<vector<bool>> dic_zon(10, vector<bool>(10, false));
        for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                if (board[i][j] != '.') {
                    int index = board[i][j] - 48;
                    //ÐÐ
                    if (dic_row[i][index])
                        return false;
                    else
                        dic_row[i][index] = true;
                    //ÁÐ
                    if (dic_col[j][index])
                        return false;
                    else
                        dic_col[j][index] = true;
                    //3x3
                    int zone = i / 3 * 3 + j / 3;
                    if (dic_zon[zone][index])
                        return false;
                    else
                        dic_zon[zone][index] = true;
                }
            }
        }
        return true;
    }
};
int main() {
    Solution S;
    vector<vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
        , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
        , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
        , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
        , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
        , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
        , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
        , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
        , {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
    cout << S.isValidSudoku(board) << endl;
    return 0;
}