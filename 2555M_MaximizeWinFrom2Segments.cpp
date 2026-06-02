#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int maximizeWin(vector<int> &prizePositions, int k) {
        int res = 0;
        if (prizePositions.empty()) {
            return 0;
        }
        if (k == 0) {
            if (prizePositions.size() >= 2) {
                return 2;
            } else {
                return prizePositions.size();
            }
        }

        unordered_map<int, int> cnt;
        for (auto &p : prizePositions) {
            cnt[p] += 1;
        }
        int leftBound = prizePositions[0];
        int rightBound = prizePositions[prizePositions.size() - 1];
        vector<int> dp(rightBound + 1, 0);
        for (int i = leftBound; i <= rightBound; ++i) {
            if (i > 0) {
                dp[i] = dp[i - 1];
            }
            if (i - k - 1 >= leftBound) {
                if (cnt.find(i - k - 1) != cnt.end()) {
                    dp[i] -= cnt[i - k - 1];
                }
            }
            if (cnt.find(i) != cnt.end()) {
                dp[i] += cnt[i];
            }
            int second = secondSegmentMaxPrize(prizePositions, cnt, i, k);
            int total = second + dp[i];
            res = max(res, total);
        }
        return res;
    }

  private:
    int secondSegmentMaxPrize(vector<int> &prizePositions,
                              unordered_map<int, int> &cnt, int start, int k) {
        int rightBound = prizePositions[prizePositions.size() - 1];
        if (start > rightBound) {
            return 0;
        }
        int res = 0;
        vector<int> dp(rightBound + 1, 0);
        for (int i = rightBound; i > start; --i) {
            if (i < rightBound) {
                dp[i] = dp[i + 1];
            }
            if (i + k + 1 <= rightBound) {
                if (cnt.find(i + k + 1) != cnt.end()) {
                    dp[i] -= cnt[i + k + 1];
                }
            }
            if (cnt.find(i) != cnt.end()) {
                dp[i] += cnt[i];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> prizePositions = {1, 1, 2, 2, 3, 3, 5};
    int k = 2;
    int res = s.maximizeWin(prizePositions, k);
    cout << "result:" << res << "\r\n";
    return 0;
}