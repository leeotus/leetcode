#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    // 动规
    int countSubstrings(string s) {
        int ret{0};
        int len = s.size();
        vector<vector<bool>> dp;
        dp.reserve(len);
        for(int i = 0; i < len; ++i) {
            dp.emplace_back(vector<bool>(len, false));
        }
        
        // 初始化
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(i == j) {
                    dp[i][j] = true;
                    ret += 1;
                }
            }
        }
        
        for(int i = 1; i < len; ++i) {
            for(int j = 0; j < i; ++j) {
                if(j+1 == i && s[j] == s[i]) {
                    dp[i][j] = true;
                    ret += 1;
                } else if(i > j+1) {
                    if(isPalindromic(dp, s, i, j)) {
                        ret += 1;
                    }
                }
            }
        }
        return ret;
    }
private:
    bool isPalindromic(vector<vector<bool>> &pld, string &s, int i, int j) {
        if(i == j) {
            pld[i][j] = true;
            return true;
        }
        if(i == j + 1) {
            if(s[i] == s[j]) {
                pld[i][j] = true;
                return true;
            }
            pld[i][j] = false;
            return false;
        }
        // i > j+1
        if(s[i] == s[j] && pld[i-1][j+1]) {
            pld[i][j] = true;
            return true;
        }
        pld[i][j] = false;
        return false;
    }
};

int main(int argc, char **argv) {
    string s = "aaaaa";
    Solution slt;
    auto ret = slt.countSubstrings(s);
    cout << "result:" << ret << "\r\n";
    return 0;
}
