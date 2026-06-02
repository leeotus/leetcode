#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minRemoval(vector<int> &nums, int k) {
        int res1 = 0;
        int res2 = INT32_MAX;
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int left = -1, right = 0;
        for (; right < nums.size(); ++right) {
            if ((long long)nums[right] > k * (long long)nums[left + 1]) {
                res2 = min((unsigned long)res2, nums.size() - right + left + 1);
                while ((long long)nums[right] > k * (long long)nums[left + 1] &&
                       left + 1 < right) {
                    res1 += 1;
                    ++left;
                }
            }
        }
        return min(res2, res1);
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {32, 607, 740, 134, 944, 91, 410, 155, 493, 89, 12};
    int k = 10;
    Solution s;
    int res = s.minRemoval(nums, k);
    cout << "result:" << res << "\r\n";
    return 0;
}