#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }

        int len = nums.size();
        vector<int> dp1(len + 1, 0); // 拿了第一家钱的dp
        vector<int> dp2(len + 1, 0); // 不拿第一家钱的dp
        dp1[1] = nums[0];
        dp2[2] = nums[1];

        int ret = 0;

        for (int i = 3; i < len + 1; ++i) {
            if(i == len) {
                dp1[i] = max(dp1[i-1], dp1[i-2]);
            } else {
                dp1[i] = max(dp1[i-2], dp1[i-3]) + nums[i-1];
            }
            dp2[i] = max(dp2[i-2], dp2[i-3]) + nums[i-1];
        }

        return max(max(dp1[len], dp1[len - 1]), max(dp2[len], dp2[len - 1]));
    }
};

int main(int argc, char **argv) {
    // vector<int> nums = {2, 3, 2};
    vector<int> nums = {1, 2, 3, 1};
    Solution slt;
    int ret = slt.rob(nums);
    cout << "result:" << ret << "\r\n";
    return 0;
}