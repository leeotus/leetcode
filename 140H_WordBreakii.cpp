#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ret.clear();
        string sentence{};
        set<string> dict;
        for(auto &str : wordDict) {
            dict.insert(str);
        }
        backtracking(s, dict, sentence);
        return ret;
    }
private:
    vector<string> ret;

    void backtracking(string &in, set<string> &dict, string &sentence) {
        // 边界条件
        if(in.empty()) {
            ret.push_back(sentence);
            return;
        }

        int len = in.size();
        vector<bool> dp(len + 1, false);
        dp[0] = true;

        for (int i = 1; i < len + 1; ++i) {
            string sub;
            for(int j = 0; j < i; ++j) {
                sub = in.substr(j, i - j);
                dp[i] = (dp[i] || dp[j] && dict.find(sub) != dict.end());
                if(dp[i]) {
                    break;
                }
            }
            if(dp[i]) {
                // 只有dp[in.size()]也满足拆分条件的时候才会触发边界条件,
                // 从而把sentence放入到ret中
                string another_in = in.substr(i);
                int push_len{0};
                if (sentence.empty()) {
                    sentence += sub;
                    push_len = sub.size();
                } else {
                    sentence = sentence + " " + sub;
                    push_len = sub.size() + 1;
                }
                backtracking(another_in, dict, sentence);
                while(push_len--) {
                    // 回溯，恢复字符串
                    sentence.pop_back();
                    dp[i] = false;
                }
            }
        }
    }
};

int main(int argc, char **argv) {
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    Solution slt;
    auto ret = slt.wordBreak(s, wordDict);
    for(auto s : ret) {
        cout << s << "\r\n";
    }
    return 0;
}
