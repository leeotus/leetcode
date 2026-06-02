#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return vector<vector<string>>();
        }

        backtracking(s, 0);
        return ans;
    }

  private:
    vector<vector<string>> ans{};
    vector<string> collect{};

    void backtracking(string &s, int startIndex) {
        int n = s.size();
        if (startIndex == n) {
            ans.push_back(collect);
            return;
        }

        for (int i = startIndex; i <= n; ++i) {
            string sub = s.substr(startIndex, i - startIndex + 1);
            if (isPalindrome(sub)) {
                collect.push_back(sub);
                backtracking(s, i + 1);
                collect.pop_back();
            }
        }
    }

    // @brief 先做一个简单的回文子串的判断
    bool isPalindrome(string &in) {
        if (in.empty()) {
            return false;
        }
        int n = in.size();
        for (int i = 0; i < n / 2; ++i) {
            if (in[i] != in[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    string in = "aab";
    Solution slt;
    auto res = slt.partition(in);
    for (auto v : res) {
        for (auto s : v) {
            cout << s << " ";
        }
        cout << "\r\n";
    }
    return 0;
}