#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // 1 <= n == costs.length <= 10e5
    int climbStairs(int n, vector<int> &costs) {
        vector<int> dp(n + 1, 0);
        // dp[i]表示跳到第i个楼梯的最小代价
        dp[1] = costs[0] + 1;
        if (n == 1) {
            return dp[1];
        }
        dp[2] = min(4 + costs[1], dp[1] + 1 + costs[1]);
        for (int i = 3; i <= n; ++i) {
            int cost1 = dp[i - 3] + 9;
            int cost2 = dp[i - 2] + 4;
            int cost3 = dp[i - 1] + 1;
            dp[i] = min(min(cost1, cost2), cost3) + costs[i - 1];
        }
        return dp[n];
    }
};

int main(int argc, char **argv) { return 0; }