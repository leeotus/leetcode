#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        long long res = 0;
        set<int> dumplicates;
        if (nums.size() < k) {
            return res;
        }
        int left = -1, right = 0;
        unordered_map<int, int> cnt;
        long long sum = 0;
        bool ok = true;
        while (right < k) {
            sum += (long long)nums[right];
            cnt[nums[right]] += 1;
            if (cnt[nums[right]] >= 2) {
                dumplicates.insert(nums[right]);
                ok = false;
            }
            ++right;
        }
        if (ok) {
            res = max(res, sum);
        }
        for (; right < nums.size(); ++right) {
            ++left;
            sum -= nums[left];
            cnt[nums[left]] -= 1;
            if (cnt[nums[left]] == 1) {
                dumplicates.erase(nums[left]);
                if (dumplicates.empty()) {
                    ok = true;
                }
            }
            sum += (long long)nums[right];
            cnt[nums[right]] += 1;
            if (cnt[nums[right]] >= 2) {
                dumplicates.insert(nums[right]);
                ok = false;
            }
            if (ok) {
                res = max(res, sum);
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1, 1, 1, 7, 8, 9};
    int k = 3;
    Solution s;
    auto res = s.maximumSubarraySum(nums, k);
    cout << "result: " << res << "\r\n";
    return 0;
}