#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        
        int len = nums.size();
        vector<int> dp(len + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];    // 第一家
        dp[2] = nums[1];    // 第二家
        for (int i = 3; i < len + 1; ++i) {
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i - 1];
        }

        return max(dp[len], dp[len-1]);
    }
};

int main(int argc, char **argv) {
    // vector<int> nums = {1, 2, 3, 1};
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution slt;
    int ret = slt.rob(nums);
    cout << "result:" << ret << "\r\n";
    return 0;
}