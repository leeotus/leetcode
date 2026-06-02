#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 366000);
        dp[days[0]] = min(min(costs[0], costs[1]), costs[2]);
        for (int i = 1; i < days.size(); ++i) {
            int last7, last30;
            // 可以改成二分查找
            int j;
            for (j = i; j >= 0; --j) {
                if (days[i] - days[j] >= 7) {
                    break;
                }
            }
            if (j >= 0) {
                last7 = days[j];
            } else {
                last7 = -1;
            }
            if(last7 >= 0) {
                for (j = last7; j >= 0; --j) {
                    if (days[i] - days[j] >= 30) {
                        break;
                    }
                }
            }
            if (j >= 0) {
                last30 = days[j];
            } else {
                last30 = -1;
            }
            
            if(last7 == -1) {
                dp[days[i]] = min(min(costs[1], dp[days[i - 1]] + costs[0]), costs[2]);
            } else if(last30 == -1) {
                dp[days[i]] = min(min(dp[last7] + costs[1], dp[days[i-1]] + costs[0]), costs[2]);
            } else {
                dp[days[i]] = min(min(dp[last7] + costs[1], dp[last30] + costs[2]),
                              dp[days[i - 1]] + costs[0]);
            }

        }
        return dp[days[days.size() - 1]];
    }
};

int main(int argc, char **argv) {
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {7, 2, 15};
    Solution slt;
    auto ret = slt.mincostTickets(days, costs);
    cout << "result: " << ret << "\r\n";
    return 0;
}