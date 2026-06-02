#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ret = 1000;
        if(triangle.empty()) {
            return 0;
        }
        
        int len = triangle.size();
        vector<int> dp(len, 1000);
        
        dp[0] = triangle[0][0];
        for(int i = 1; i < len; ++i) {
            int tl = triangle[i].size();
            for(int j = 0; j < tl; ++j) {
                if (j - 1 >= 0 && j < triangle[i - 1].size()) {
                    dp[i] = min(dp[i], triangle[i][j] +
                            min(triangle[i - 1][j], triangle[i - 1][j - 1]));
                } else {
                    dp[i] = min(dp[i], triangle[i - 1][0] + triangle[i][j]);
                }
                ret = min(ret, dp[i]);
            }
        }

        return ret;
    }
    
    int minimumTotal2(vector<vector<int>> &triangle) {
        int len = triangle.size();
        vector<vector<int>> dp(len, vector<int>(len, 1000));
        dp[0][0] = triangle[0][0];
        int ret = dp[0][0];
        for(int i = 1; i < len; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(j == 0 || j == i) {
                    if(j == 0) {
                        dp[i][j] = dp[i-1][j] + triangle[i][j];
                    } else if(j == i) {
                        dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                    }
                } else {
                    dp[i][j] =
                        min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }
        
        ret = dp[len-1][0];
        for(int i = 0; i < len; ++i) {
            if(dp[len-1][i] < ret) {
                ret = dp[len-1][i];
            }
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    // vector<vector<int>> triangle = {
    //     {2},
    //     {3, 4},
    //     {6, 5, 7},
    //     {4, 1, 8, 3}
    // };
    /* vector<vector<int>> triangle = {
        {-1},
        {-2, -3}
    }; */
    vector<vector<int>> triangle = {
        {-1},
        {3, 2},
        {-3, 1, -1}
    };
    Solution slt;
    auto ret = slt.minimumTotal2(triangle);
    cout << "result:" << ret << "\r\n";
    return 0;
}