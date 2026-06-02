#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit2(vector<int> &prices) {
        if(prices.size() <= 1) {
            return 0;
        }
        
        int days = prices.size();
        int ret = 0;
        vector<int> dp(days, 0);
        for(int i = 1; i < days; ++i) {
            int profit = prices[i] - prices[i-1];
            dp[i] = max(max(profit + ret, dp[i-1] + profit), dp[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) {
            return 0;
        }
        
        int days = prices.size();
        vector<int> dp(days, 0);
        for(int i=1; i < days;++i) {
            int dx = prices[i] - prices[i-1];
            if (dp[i - 1] + dx >= 0) {
                dp[i] = dp[i - 1] + dx;
            } else {
                dp[i] = 0;
            }
        }
        
        vector<int> get;
        int ret = 0;
        int left = 0, right = 0;
        while(right < dp.size()) {
            while (right + 1 < dp.size() && dp[right + 1] >= dp[left]) {
                ++right;
            }
            if(dp[right] > 0 && right - left >= 1) {
                get.push_back(dp[right]);
            }
            right += 1;
            left = right;
        }
        
        if(get.empty()) {
            return ret;
        }

        sort(get.begin(), get.end());
        if(get.size() > 1) {
            ret = get[0] + get[1];
        } else {
            ret = get[0];
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution slt;
    auto ret = slt.maxProfit2(prices);
    cout << "result:" << ret << "\r\n";
    return 0;
}