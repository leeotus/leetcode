#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret = 0;
        if(matrix.empty()) {
            return ret;
        }

        int a = matrix.size();
        int b = matrix[0].size();
        vector<vector<int>> dp(a, vector<int>(b, 0));

        for (int i = 0; i < a; ++i) {
            if (matrix[i][0] == '1') {
                ret = 1;
            }
            dp[i][0] = matrix[i][0] - '0';
        }
        for(int j = 0; j < b; ++j) {
            if (matrix[0][j] == '1') {
                ret = 1;
            }
            dp[0][j] = matrix[0][j] - '0';
        }
        
        for(int i = 1; i < a; ++i) {
            for (int j = 1; j < b; ++j) {
                if(matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    int cnt = 1;
                    int ii = i;
                    int jj = j;
                    while (--ii >= 0 && --jj >= 0 && dp[ii][jj] >= 1) {
                        bool squareOk = true;
                        for(int m = ii; m < i; ++m) {
                            if(matrix[m][j] == '0') {
                                squareOk = false;
                                break;
                            }
                        }
                        for (int n = jj; n < j; ++n) {
                            if (matrix[i][n] == '0') {
                                squareOk = false;
                                break;
                            }
                        }
                        if(squareOk && dp[i-1][j-1] >= cnt * cnt) {
                            ++cnt;
                        }
                    }
                    dp[i][j] = cnt * cnt; // for debug
                    ret = max(ret, dp[i][j]);
                }
            }
        }

        return ret;
    }

    int maximalSquare2(vector<vector<char>> &matrix) {
        int ret = 0;
        if(matrix.empty()) {
            return ret;
        }
        int a = matrix.size();
        int b = matrix[0].size();
        
        vector<vector<int>> dp(a, vector<int>(b, 0));

        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                if(matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                        if(ret == 0) {
                            ret = 1;
                        }
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                        ret = max(ret, dp[i][j]);
                    }
                }
            }
        }

        return ret * ret;
    }
};

int main(int argc, char **argv) {
    Solution slt;
    vector<vector<char>> matrix = {
        {'0', '1', '1', '0', '1'},
        {'1', '1', '0', '1', '0'},
        {'0', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '1'},
        {'0', '0', '0', '0', '0'}
    };
    int ret = slt.maximalSquare2(matrix);
    cout << "result:" << ret << "\r\n";
    return 0;
}