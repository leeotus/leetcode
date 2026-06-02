#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minSubArrayLenv2(int target, vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = INT32_MAX;
        int left = -1, right = 0;
        int sum = 0;
        for (; right < nums.size(); ++right) {
            sum += nums[right];
            if (sum >= target) {
                res = min(res, right - left);
                while (left < right) {
                    ++left;
                    sum -= nums[left];
                    if (sum < target) {
                        break;
                    }
                    res = min(res, right - left);
                }
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    Solution s;
    int res = s.minSubArrayLen(target, nums);
    cout << "result:" << res << "\r\n";
    return 0;
}