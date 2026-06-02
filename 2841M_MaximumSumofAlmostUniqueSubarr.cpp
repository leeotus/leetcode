#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    long long maxSum(vector<int> &nums, int m, int k) {
        long long res = 0;
        if (nums.empty()) {
            return 0;
        }
        int left = -1, right = 0;
        int uniq = 0;
        unordered_map<int, int> cnt;
        long long sum = 0;
        while (right < k) {
            if (cnt[nums[right]] == 0) {
                uniq += 1;
            }
            cnt[nums[right]] += 1;
            sum += (long long)nums[right];
            ++right;
        }
        if (uniq >= m) {
            res = max(res, sum);
        }

        for (; right < nums.size(); ++right) {
            ++left;
            cnt[nums[left]] -= 1;
            sum -= nums[left];
            if (cnt[nums[left]] == 0) {
                uniq -= 1;
            }
            if (cnt[nums[right]] == 0) {
                uniq += 1;
            }
            cnt[nums[right]] += 1;
            sum += (long long)nums[right];

            if (uniq >= m) {
                res = max(res, sum);
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return 0;
}