#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        if(nums.size() == 1) {
            // nums not empty
            return ret;
        }
        int len = nums.size();
        vector dp(len, 0);
        dp[0] = nums[0];
        for(int i = 1; i < len; ++i) {
            dp[i] = max((dp[i-1] + nums[i]), nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main(int argc, char **argv) {

    return 0;
}