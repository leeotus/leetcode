#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxVowels(string s, int k) {
        int res = 0;
        if (s.empty()) {
            return 0;
        }
        int left = -1, right = 0;
        int len = 0;
        for (; right < s.size(); ++right) {
            if (right - left > k) {
                ++left;
                if (vowels.find(s[left]) != vowels.end()) {
                    len -= 1;
                }
            }
            if (vowels.find(s[right]) != vowels.end()) {
                ++len;
            }
            if (len == k) {
                return len;
            }
            res = max(res, len);
        }
        return res;
    }

  private:
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
};

int main(int argc, char **argv) { return 0; }