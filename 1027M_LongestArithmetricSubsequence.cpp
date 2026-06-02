#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> seq;
        for(int i = 1; i < nums.size(); ++i) {
            int cur = nums[i];
            for(int j = 0; j < i; ++j) {
                int delt = cur - nums[j];
                if(seq.find(delt) == seq.end()) {
                    seq[delt] = 2;
                } else {
                    seq[delt] += 1;
                }
                ret = max(ret, seq[delt]);
            }
        }
        return ret;
    }
    
    int longestArithSeqLength2(vector<int> &nums) {
        // nums.size() ~ [2, 1000]
        int ret = 2;
        int len = nums.size();
        vector<int> dp(len, 2);
        vector<int> dn(len, 0); // 公差数组
        dn[1] = nums[1] - nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            int cur = nums[i];
            for(int j = 0; j < i; ++j) {
                int delt = cur - nums[j];
                if (delt == dn[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    ret = max(ret, dp[i]);
                    dn[i] = delt;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    // vector<int> nums = {83, 20, 17, 43, 52, 78, 68, 45};
    // vector<int> nums = {3, 6, 9, 12};
    vector<int> nums = {9, 4, 7, 2, 10};
    Solution slt;
    auto ret = slt.longestArithSeqLength2(nums);
    cout << "result:" << ret << "\r\n";
    return 0;
}