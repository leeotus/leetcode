#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            s.insert(nums[i]);
        }

        int res = 1;
        for (; res <= n; ++res) {
            if (s.find(res) != s.end()) {
                continue;
            } else {
                break;
            }
        }

        return res;
    }

    int firstMissingPositiveII(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int j = 0; j < n; ++j) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }
        return n;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {3, 4, -1, 1};
    Solution slt;
    int res = slt.firstMissingPositiveII(nums);
    cout << "result:" << res << "\r\n";
    return 0;
}