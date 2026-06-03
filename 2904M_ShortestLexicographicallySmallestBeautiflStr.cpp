#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        int left = -1, right = 0;
        int cnt = 0;
        while (cnt < k && right < s.size()) {
            if (s[right] == '1') {
                cnt += 1;
                if (cnt == k) {
                    break;
                }
            }
            ++right;
        }
        if (right == s.size() && cnt != k) {
            return res;
        }

        // 去除多余的0
        while (s[left + 1] == '0') {
            ++left;
        }
        res = s.substr(left + 1, right - left);

        ++right;
        for (; right < s.size(); ++right) {
            if (s[right] == '1') {
                while (left < right) {
                    ++left;
                    if (s[left] == '1') {
                        break;
                    }
                }
                // 去除多余的0
                while (s[left + 1] == '0') {
                    ++left;
                }
            }

            if (s[right] != '0') {
                string str = s.substr(left + 1, right - left);
                if (str.size() < res.size() ||
                    (str.size() == res.size() && str < res)) {
                    res = str;
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    string s = "100011001";
    int k = 3;
    Solution slt;
    string res = slt.shortestBeautifulSubstring(s, k);
    cout << "result:" << res << "\r\n";
    return 0;
}