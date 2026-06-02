#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        if (s.empty()) {
            return 0;
        }
        unordered_map<char, int> cnt;
        int left = -1, right = 0;
        for (; right < s.size(); ++right) {
            cnt[s[right]] += 1;
            if (cnt[s[right]] >= 3) {
                while (left < right) {
                    ++left;
                    cnt[s[left]] -= 1;
                    if (s[left] == s[right]) {
                        break;
                    }
                }
            }
            int len = right - left;
            res = max(res, len);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return 0;
}