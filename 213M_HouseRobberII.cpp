#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int n = nums.size();
        // 区分情况, 第一家是否要抢劫?
        // 1. 第一家要抢劫
        vector<int> dp1(n + 1, 0);
        dp1[1] = nums[0];
        // 2. 第一家不抢劫
        vector<int> dp2(n + 1, 0);
        dp2[2] = nums[1];

        for (int i = 2; i < n; ++i) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
        }
        for (int i = 3; i <= n; ++i) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
        }
        int res1 = max(dp1[n], dp1[n - 1]);
        int res2 = max(dp2[n], dp2[n - 1]);
        return max(res1, res2);
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1, 2, 3};
    Solution s;
    int res = s.rob(nums);
    cout << "result:" << res << "\r\n";
    return 0;
}