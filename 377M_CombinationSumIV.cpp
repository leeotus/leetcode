#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    // 1 <= nums[i] <= 1000
    int combinationSum4(vector<int> &nums, int target) {
        // dp[i]表示用nums中元素组成和为i的组合的个数
        vector<int> dp(target + 1, 0);
        sort(nums.begin(), nums.end());
        for (auto &n : nums) {
            if (n <= target) {
                dp[n] += 1;
            }
        }
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] > i) {
                    break;
                }
                dp[i] += (dp[i - nums[j]]);
            }
        }
        return dp[target];
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1, 2, 3};
    int target = 4;
    Solution s;
    auto res = s.combinationSum4(nums, target);
    cout << "result:" << res << "\r\n";
    return 0;
}