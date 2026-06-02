#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if(s.empty()) {
            // ?空字符串也是回文串吗?
            return false;
        }
        if(s.size() == 1) {
            return true;
        }
        int left = 0, right = s.size() - 1;
        return validate(s, left, right);
    }

private:
    bool dumplicate = false;

    bool validate(string &s, int left, int right) {
        while(left < right) {
            if(s[left] == s[right]) {
                ++left;
                --right;
            } else if(s[left] != s[right]) {
                if (dumplicate) {
                    return false;
                }
                // 已经找到一个可能导致回文串不成立的字符
                dumplicate = true;
                return validate(s, left + 1, right) ||
                       validate(s, left, right - 1);
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    string s{"abca"};
    Solution slt;
    auto ret = slt.validPalindrome(s);
    cout << "result:" << (ret ? "true" : "false") << "\r\n";
    return 0;
}