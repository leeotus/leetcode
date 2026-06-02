#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        if(nums.empty()) {
            return res;
        }
        for(int l = 0; l < nums.size(); ++l) {
            int r = l;
            int sum = 0;
            while (r < nums.size()) {
                sum += nums[r];
                r++;
                if(sum == k) {
                    res += 1;
                }
            }
        }
        return res;
    }
    
    int subarraySumII(vector<int> &nums, int k) {
        int res = 0;
        int s = nums.size();
        vector<int> preSum(s + 1, 0);
        unordered_map<int, int> dict;
        dict[0] += 1;
        for(int i = 1; i < s+1; ++i) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            dict[preSum[i]] += 1;
        }
        for(int i = 0; i < preSum.size(); ++i) {
            if (dict.find(preSum[i] + k) != dict.end()) {
                res += dict[preSum[i] + k];
            }
        }
        return res;
    }
    
    int subarraySumIII(vector<int> &nums, int k) {
        int res = 0;
        unordered_map<int, int> dict;
        vector<int> preSum(nums.size() + 1, 0);
        dict[0] = 1;
        for(int i = 1; i < preSum.size(); ++i) {
            preSum[i] = preSum[i-1] + nums[i-1];
            res += dict[preSum[i] - k];
            dict[preSum[i]] += 1;
        }
        return res;
    }
};

int main(int argc, char **argv) {
    // vector<int> nums = {1, 1, 1};
    // vector<int> nums = {1, -1, 0};
    vector<int> nums = {6, 4, 3, 1};
    // int k = 2;
    int k = 10;
    // int k = 0;
    Solution slt;
    int res = slt.subarraySumIII(nums, k);
    cout << "result:" << res << "\r\n";
    return 0;
}