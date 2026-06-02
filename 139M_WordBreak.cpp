#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len + 1, false);
        set<string> dict;
        for(auto &str : wordDict) {
            dict.insert(str);
        }
        dp[0] = true; // 表示空字符串可以被匹配成功

        for (int i = 1; i < len + 1; ++i) {
            for(int j = 0; j < i; ++j) {
                string sub = s.substr(j, i - j);
                dp[i] = (dp[i] || dp[j] && dict.find(sub) != dict.end());
            }
        }

        return dp[len];
    }
};

int main(int argc, char **argv) {
    // string s = "leetcode";
    // string s = "applepenapple";
    string s = "catsandog";
    // vector<string> wordDict = {"leet", "code"};
    // vector<string> wordDict = {"apple", "pen"};
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    Solution slt;
    auto ret = slt.wordBreak(s, wordDict);
    cout << "result:" << (ret ? "true" : "false") << "\r\n";
    return 0;
}