#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // @note nums.size() > 1
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size();
        rotating(nums, 0, k);
        assert(!nums.empty());
    }

    void rotateII(vector<int> &nums, int k) {
        if (k == 0) {
            return;
        }
        int n = nums.size();
        k = k % n;
        int cnt = gcd(n, k);
        for (int i = 0; i < cnt; ++i) {
            int start = i;
            int cur = i;
            int next = (cur + k) % n;
            while (next != start) {
                swap(nums[cur], nums[next]);
                cur = next;
                next = (cur + k) % n;
            }
        }
    }

  private:
    // 求最大公约数
    int gcd(int n, int k) {
        int res = 1;
        for (int i = 1; i <= min(n, k); ++i) {
            if ((n % i == 0) && (k % i == 0)) {
                res = i;
            }
        }
        return res;
    }

    void rotating(vector<int> &in, int pos, int k) {
        int len1 = in.size() - k - pos;
        int len2 = k;
        if (pos >= in.size() - 1 || len1 == 0 || k == 0) {
            return;
        }
        int start = len1 + pos;
        while (start < in.size()) {
            swap(in[start], in[start - len1]);
            ++start;
        }
        pos = len2;
        k = k % len1;
        rotating(in, pos, k);
    }
};

int main(int argc, char **argv) {
    Solution slt;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    // vector<int> nums = {-1, -100, 3, 99};
    int k = 3;
    slt.rotateII(nums, k);
    for (auto &n : nums) {
        cout << n << " ";
    }
    cout << "\r\n";
    return 0;
}