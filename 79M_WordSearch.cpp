#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> used(n, vector<bool>(m, false));
        backtracking(board, 0, 0, used, word, 0);
        return ans;
    }

  private:
    int n{0};
    int m{0};
    bool ans{false};

    void backtracking(vector<vector<char>> &board, int istart, int jstart,
                      vector<vector<bool>> &used, string &word, int index) {
        if (index == word.size()) {
            ans = true;
            return;
        }
        if ((istart < 0 || istart > n - 1) || (jstart < 0 || jstart > m - 1) ||
            index >= word.size()) {
            return;
        }
        if (used[istart][jstart]) {
            return;
        }
        for (int i = istart; i < n; ++i) {
            for (int j = jstart; j < m; ++j) {
                if (used[i][j]) {
                    continue;
                }
                if (board[i][j] == word[index]) {
                    used[i][j] = true;
                    if (j != 0 && !used[i][j - 1]) {
                        // 左移
                        backtracking(board, i, j - 1, used, word, index + 1);
                    }
                    if (j != m - 1 && !used[i][j + 1]) {
                        // 右移
                        backtracking(board, i, j + 1, used, word, index + 1);
                    }
                    if (i != 0 && !used[i - 1][j]) {
                        // 上移
                        backtracking(board, i - 1, j, used, word, index + 1);
                    }
                    if (i != n - 1 && !used[i + 1][j]) {
                        // 下移
                        backtracking(board, i + 1, j, used, word, index + 1);
                    }
                    // 不需要移动的情况:
                    if (word.size() == 1) {
                        ans = true;
                    }
                    used[i][j] = false;
                }
            }
        }
    }
};

int main(int argc, char **argv) {
    // vector<vector<char>> board = {{'b', 'b'}, {'a', 'b'}, {'b', 'a'}};
    vector<vector<char>> board = {{'a'}};
    string word = "a";
    Solution slt;
    auto res = slt.exist(board, word);
    cout << "result:" << res << "\r\n";
    return 0;
}