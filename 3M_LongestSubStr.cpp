#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dict;
        int res{0};
        int left = 0, right = 0;
        for (; right < s.size(); ++right) {
            char cur = s[right];
            if (dict[cur] >= 1) {
                // 有重复的了
                while (left < right && s[left] != cur) {
                    dict[s[left]] -= 1;
                    ++left;
                }
                dict[s[left]] -= 1;
                ++left;
                --right;
            } else {
                dict[cur] += 1;
                res = max(res, right - left + 1);
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    string in = "abcabcbb";
    // string in = "tmmzuxt";
    Solution slt;
    int result = slt.lengthOfLongestSubstring(in);
    cout << "result:" << result << "\r\n";
    return 0;
}