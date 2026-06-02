#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ret = 0;
        if(matrix.empty()) {
            return ret;
        }
        int a = matrix.size();
        int b = matrix[0].size();

        vector<vector<int>> dp(a, vector<int>(b, 0));

        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                if(matrix[i][j] == 1) {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                    }
                    ret += dp[i][j];
                }
            }
        }

        return ret;
    }
};

int main(int argc, char **arv) {
    return 0;
}