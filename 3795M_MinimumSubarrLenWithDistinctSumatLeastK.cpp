#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minLength(vector<int> &nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> cnt(1e5 + 1, 0);
        int left = -1, right = 0;
        int res = INT32_MAX;
        int sum = 0;
        for (; right < nums.size(); ++right) {
            cnt[nums[right]] += 1;
            if (cnt[nums[right]] == 1) {
                sum += nums[right];
            }
            while (sum >= k && left < right) {
                res = min(res, right - left);
                ++left;
                cnt[nums[left]] -= 1;
                if (cnt[nums[left]] == 0) {
                    sum -= nums[left];
                }
            }
        }
        return res == INT32_MAX ? -1 : res;
    }
};