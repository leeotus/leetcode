#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &nums) {
        int res = 0;
        if (nums.empty()) {
            return 0;
        }
        bool dumplicateZero = false;
        int left = -1, right = 0;

        for (; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                if (!dumplicateZero) {
                    dumplicateZero = true;
                } else {
                    while (left < right) {
                        ++left;
                        if (nums[left] == 0) {
                            break;
                        }
                    }
                }
            }
            int len = right - left;
            res = max(res, len);
        }

        return res - 1;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    Solution s;
    auto res = s.longestSubarray(nums);
    cout << "result:" << res << "\r\n";
    return 0;
}