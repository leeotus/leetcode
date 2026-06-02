#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestSemiRepetitiveSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int res = 0;
        int left = -1, right = 1;
        int dump = -1; // 重复字符对的第二个字符所在的索引
        for (; right < s.size(); ++right) {
            if (s[right] == s[right - 1]) {
                // 出现了重复的字符
                if (dump != left) {
                    // 说明前面还有一对重复的字符对
                    if (s[dump] != s[dump + 1] || dump == right - 1) {
                        // 当s[dump] != s[dump+1] 或者 dump ==
                        // right-1的时候可以保留重复字符对的右边那个字符
                        left = dump - 1;
                    } else {
                        left = dump;
                    }
                }
                dump = right;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    ;
    Solution s;
    string str = "11111";
    int res = s.longestSemiRepetitiveSubstring(str);
    cout << "result:" << res << "\r\n";
    return 0;
}