#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // n >= 1
    int numSquares(int n) {
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

int main(int argc, char **argv) {
    Solution slt;
    int result = slt.numSquares(12);
    cout << "result:" << result << "\r\n";
    return 0;
}