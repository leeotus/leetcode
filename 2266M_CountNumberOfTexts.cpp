#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countTexts(string pressedKeys) {
        vector<vector<int>> cnt(10, vector<int>{0, 1, 2, 4});
        cnt[7].push_back(8);
        cnt[9].push_back(8);

        int n = pressedKeys.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < n + 1; ++i) {
            dp[i] += dp[i - 1];
            dp[i] %= modNum;

            if (i - 2 >= 0 && pressedKeys[i - 1] == pressedKeys[i - 2]) {
                dp[i] += dp[i - 2] * cnt[pressedKeys[i - 1] - '0'][2];
                dp[i] %= modNum;
            }
            if (i - 3 >= 0 && pressedKeys[i - 1] == pressedKeys[i - 3]) {
                dp[i] += dp[i - 3] * cnt[pressedKeys[i - 1] - '0'][3];
                dp[i] %= modNum;
            }
            if (i - 4 >= 0 &&
                (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') &&
                pressedKeys[i - 1] == pressedKeys[i - 4]) {
                dp[i] += dp[i - 4] * cnt[pressedKeys[i - 1] - '0'][4];
                dp[i] %= modNum;
            }
        }
        return dp[n];
    }

  private:
    int modNum = 1e9 + 7;
};

int main(int argc, char **argv) {
    Solution s;
    string str = "22233";
    int res = s.countTexts(str);
    cout << "res: " << res << "\r\n";
    return 0;
}