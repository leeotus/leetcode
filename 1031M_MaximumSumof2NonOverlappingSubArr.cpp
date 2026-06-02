#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        int len = nums.size();
        vector<int> preSum(len + 1, 0); // 前缀和
        for (int i = 1; i <= len; ++i) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        // 左闭右开
        auto sumof = [&](int l, int r) { return preSum[r] - preSum[l]; };

        int res = 0;
        // 表示firstLen/secondLen数组在nums[i](不含)之前的子数组最大和
        vector<int> dp(len, 0);

        auto f = [&](int first, int second) {
            for (int i = first; i <= nums.size() - second; ++i) {
                if (i - 1 >= 0) {
                    dp[i] = max(dp[i - 1], sumof(i - first, i));
                }
                int total = dp[i] + sumof(i, i + second);
                res = max(res, total);
            }
        };
        f(firstLen, secondLen);
        f(secondLen, firstLen);

        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {0, 6, 5, 2, 2, 5, 1, 9, 4};
    Solution s;
    int firstLen = 1;
    int secondLen = 2;
    int res = s.maxSumTwoNoOverlap(nums, firstLen, secondLen);
    cout << "result:" << res << "\r\n";
    return 0;
}