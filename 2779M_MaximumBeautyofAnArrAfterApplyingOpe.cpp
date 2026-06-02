#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maximumBeauty(vector<int> &nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int left = -1, right = 0;
        int maxval = nums[0] + k;
        int res = 0;
        for (; right < nums.size(); ++right) {
            int curmin = nums[right] - k;
            if (curmin > maxval) {
                // 没有交集, 需要移动左边界了
                while (left + 1 < right) {
                    if (nums[left + 1] + k >= curmin) {
                        break;
                    }
                    ++left;
                }
            }
            maxval = nums[left + 1] + k;
            res = max(res, right - left);
        }
        return res;
    }
};

int main(int argc, char **argv) { return 0; }