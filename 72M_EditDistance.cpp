#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // word1和word2可能为空
        if(word1.empty()) {
            return word2.size();
        }
        if(word2.empty()) {
            return word1.size();
        }

        int len1 = word1.size();
        int len2 = word2.size();

        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        if(word1[0] != word2[0]) {
            dp[0][0] = 1;
        }

        // 初始化dp数组
        for (int i = 1; i < len2; ++i) {
            dp[0][i] = dp[0][i - 1] + 1;
        }
        for(int j = 1; j < len1; ++j) {
            dp[j][0] = dp[j - 1][0] + 1;
        }
        
        for(int i = 1; i < len1; ++i) {
            for(int j = 1; j < len2; ++j) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1]) + 1,
                                   dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        
        return dp[len1-1][len2-1];
    }
};

int main(int argc, char **argv) {
    string word1 = "sea";
    string word2 = "eat";
    Solution slt;
    auto ret = slt.minDistance(word1, word2);
    cout << "result:" << ret << "\r\n";
    return 0;
}