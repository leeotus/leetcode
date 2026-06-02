#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestOnes(vector<int> &nums, int k) {
        int cnt = 0;
        int left = -1, right = 0;
        int res = 0;
        for (; right < nums.size(); ++right) {
            if (nums[right] == 0 && cnt >= k) {
                while (left < right) {
                    ++left;
                    if (nums[left] == 0) {
                        cnt -= 1;
                        break;
                    }
                }
            }
            if (nums[right] == 0) {
                cnt += 1;
            }
            res = max(res, right - left);
        }
        return res;
    }
};