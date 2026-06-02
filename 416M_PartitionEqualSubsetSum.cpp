#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }

        int n = nums.size();
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int t = 1; t <= target; ++t) {
                if (nums[i - 1] > t) {
                    dp[i][t] = dp[i - 1][t];
                } else {
                    dp[i][t] = max(dp[i - 1][t],
                                   dp[i - 1][t - nums[i - 1]] + nums[i - 1]);
                }
            }
        }
        return dp[n][target] == target;
    }
};

int main(int argc, char **argv) {
    Solution slt;
    vector<int> nums = {1, 5, 11, 5};
    bool res = slt.canPartition(nums);
    cout << "result:" << res << "\r\n";
    return 0;
}