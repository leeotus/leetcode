#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) {
            return vector<vector<string>>{};
        }
        n_ = n;
        // 初始化棋盘
        vector<string> board(n, string(n, '.'));
        backtracking(board, 0);
        return ans;
    }

  private:
    int n_{0};
    vector<vector<string>> ans{};

    void backtracking(vector<string> &board, int row) {
        if (row == n_) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n_; ++col) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtracking(board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isValid(const vector<string> &board, int row, int col) {
        // 检查列
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // 检查45度对角线
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // 检查135度对角线
        for (int i = row - 1, j = col + 1; i >= 0 && j < n_; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char **argv) {
    Solution slt;
    auto res = slt.solveNQueens(4);
    for (auto v : res) {
        for (auto s : v) {
            cout << s << "\r\n";
        }
        cout << "\r\n";
    }
    return 0;
}