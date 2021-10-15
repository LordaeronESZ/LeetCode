#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                bool res = func(board, visited, word, i, j, 0);
                if (res)
                    return true;
            }
        }
        return false;
    }
    bool func(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j, int k) {
        if (board[i][j] != word[k])
            return false;
        else if (k == word.size() - 1)
            return true;
        visited[i][j] = true;
        bool res = false;
        int round[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
        for (const auto& r : round) {
            int ni = i + r[0], nj = j + r[1];
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
                if (!visited[ni][nj]) {
                    bool flag = func(board, visited, word, ni, nj, k + 1);
                    if (flag) {
                        res = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
    string word = "ABCCED";
    auto res = S.exist(board, word);
    cout << res << endl;
    return 0;
}