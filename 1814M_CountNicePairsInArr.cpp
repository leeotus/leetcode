#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int countNicePairs(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        long long res = 0;
        long long modnum = 1e9 + 7;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i] - rev(nums[i]);
            if (cnt.find(cur) != cnt.end()) {
                res += cnt[cur];
                res = res % modnum;
            }
            cnt[cur] += 1;
        }
        return res % modnum;
    }

  private:
    int rev(int num) {
        int res = 0;
        while (num != 0) {
            int b = num % 10;
            res = res * 10 + b;
            num = num / 10;
        }
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {42, 11, 1, 97};
    Solution s;
    int res = s.countNicePairs(nums);
    cout << "result:" << res << "\r\n";
    return 0;
}