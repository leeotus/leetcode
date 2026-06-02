#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        if (nums.size() >= 2) {
            dp[2] = max(dp[1], nums[1]);
        }
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return max(dp[n], dp[n - 1]);
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1, 2};
    Solution s;
    int res = s.rob(nums);
    cout << "result:" << res << "\r\n";
    return 0;
}