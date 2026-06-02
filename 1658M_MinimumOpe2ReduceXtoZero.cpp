#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // note: 1 <= nums[i] <= 1e5
    int minOperations(vector<int> &nums, int x) {
        int left = 0, right = nums.size();
        int sum = 0;
        int cnt = 0;
        int res = INT32_MAX;
        while (left < right) {
            sum += nums[left];
            ++left;
            cnt += 1;
            if (sum > x) {
                break;
            }
            if (sum == x) {
                res = min(res, cnt);
            }
        }
        if (sum < x && left == right) {
            return -1;
        }
        left -= 1;
        sum -= nums[left];
        cnt -= 1;
        while (left < right && right > 0) {
            --right;
            int n = nums[right];
            while (left > 0 && sum + n > x) {
                --left;
                sum -= nums[left];
                --cnt;
            }
            sum += n;
            ++cnt;
            if (sum == x) {
                res = min(res, cnt);
            }
        }
        return res == INT32_MAX ? -1 : res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;
    Solution s;
    int res = s.minOperations(nums, x);
    cout << "result: " << res << "\r\n";
    return 0;
}
