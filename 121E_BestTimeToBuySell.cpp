#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int days = prices.size();
        if(prices.empty()) {
            return 0;
        }
        vector<int> dp(days, 0);
        for(int i = 1; i < days; ++i) {
            int profile = prices[i] - prices[i-1];
            if(dp[i-1] + profile >= 0) {
                dp[i] = dp[i-1] + profile;
                ret = max(ret, dp[i]);
            } else {
                dp[i] = 0;
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution slt;
    auto ret = slt.maxProfit(prices);
    cout << "result: " << ret << "\r\n";
    return 0;
}