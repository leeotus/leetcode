#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // @note nums.size() > 1
    int maxSubArray(vector<int> &nums) {
        int s = nums.size();
        vector<int> dp(s, 0);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < s; ++i) {
            if (dp[i - 1] + nums[i] >= nums[i]) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution slt;
    int res = slt.maxSubArray(nums);
    cout << "result:" << res << "\r\n";
    return 0;
}