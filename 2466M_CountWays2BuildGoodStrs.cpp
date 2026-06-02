#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int res = 0;
        // dp[i]表示长度为i的字符串的个数
        vector<int> dp(high + 1, 0);
        dp[0] = 0;
        dp[zero] += 1;
        dp[one] += 1;
        for (int i = 1; i <= high; ++i) {
            if (i - zero >= 0) {
                dp[i] += dp[i - zero];
            }
            if (i - one >= 0) {
                dp[i] += dp[i - one];
            }
            dp[i] %= modNum;
            if (i >= low && i <= high) {
                res += dp[i];
                res %= modNum;
            }
        }
        return res;
    }

  private:
    const int modNum = 1e9 + 7;
};

int main(int argc, char **argv) {
    int low = 3, high = 3, zero = 1, one = 1;
    Solution s;
    int res = s.countGoodStrings(low, high, zero, one);
    cout << "result:" << res << "\r\n";
    return 0;
}