#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int balancedString(string s) {
        if (s.empty()) {
            return 0;
        }
        set<char> scs = {'Q', 'W', 'E', 'R'};
        int n = s.size() / 4;
        unordered_map<char, int> cnt;
        for (auto &c : s) {
            cnt[c] += 1;
        }
        for (auto &c : scs) {
            int count = cnt[c];
            if (count - n > 0) {
                // 多余的
                cnt[c] = count - n;
            } else {
                cnt.erase(c);
            }
        }
        if (cnt.empty()) {
            return 0;
        }

        int left = -1, right = 0;
        int res = INT32_MAX;
        unordered_map<char, int> cur;

        for (; right < s.size(); ++right) {
            cur[s[right]] += 1;
            if (cnt.find(s[right]) != cnt.end() &&
                cur[s[right]] > cnt[s[right]]) {
                while (left < right) {
                    ++left;
                    cur[s[left]] -= 1;
                    if (s[left] == s[right]) {
                        break;
                    }
                }
                while (s[left + 1] != s[right] && left < right) {
                    ++left;
                    cur[s[left]] -= 1;
                }
            }
            if (validate(cur, cnt)) {
                res = min(res, right - left);
            }
        }
        return res;
    }

  private:
    bool validate(unordered_map<char, int> &cur,
                  unordered_map<char, int> &cnt) {
        for (auto &c : cnt) {
            if (c.second != cur[c.first]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    // string str = "WWEQERQWQWWRWWERQWEQ";
    // string str = "QWER";
    // string str = "QEQRWRRWWWRQQQWQQEQEQREWRQEQRQQRRQEW";
    string str = "WQWRQEQQWERQWWWEREWRQQWWWWQW";
    auto res = s.balancedString(str);
    cout << res << "\r\n";
    return 0;
}