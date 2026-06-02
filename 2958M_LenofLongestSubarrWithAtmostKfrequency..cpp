#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        // vector<int> cnt(1e9 + 1, 0); // 超过内存限制了
        unordered_map<int, int> cnt;
        int left = -1, right = 0;
        int res = 0;
        for (; right < nums.size(); ++right) {
            if (cnt[nums[right]] >= k) {
                while (left < right) {
                    ++left;
                    cnt[nums[left]] -= 1;
                    if (nums[left] == nums[right]) {
                        break;
                    }
                }
            }
            cnt[nums[right]] += 1;
            res = max(res, right - left);
        }
        return res;
    }
};
