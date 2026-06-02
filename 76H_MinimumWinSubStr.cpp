#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return string();
        }
        unordered_map<char, int> ori; // 记录t中的字符
        unordered_map<char, int> cnt; // 记录滑动窗口的子字符串

        for (auto &c : t) {
            ori[c] += 1;
        }

        // 滑动窗口的左右限
        int left = 0, right = 0;
        int start = -1; // 结果字符串的起始字符位置
        int minLen = INT_MAX;

        while (right < s.size()) {
            cnt[s[right]] += 1;

            while (check(ori, cnt) && left <= right) {
                if (right - left + 1 < minLen) {
                    start = left;
                    minLen = right - left + 1;
                }
                cnt[s[left]] -= 1;
                ++left;
            }

            ++right;
        }

        return start == -1 ? string() : s.substr(start, minLen);
    }

  private:
    bool check(unordered_map<char, int> &ori, unordered_map<char, int> &cnt) {
        for (auto it = ori.cbegin(); it != ori.cend(); ++it) {
            if (cnt[it->first] < it->second) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution slt;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    auto res = slt.minWindow(s, t);
    cout << "result: " << res << "\r\n";
    return 0;
}