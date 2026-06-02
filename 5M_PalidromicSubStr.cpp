#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string ret{s[0]};
    int left = 0, right = 0;
    for (; left < s.size(); ++left) {
      for (right = left; right <= s.size(); ++right) {
        string sub = s.substr(left, right);
        if(notParlindrome.find(sub) != notParlindrome.end()) {
            continue;
        }
        if(isPalindromic(sub) && sub.size() > ret.size()) {
            ret = sub;
        } else if(!isPalindromic(sub)) {
            notParlindrome.insert(sub);
        }
      }
    }
    return ret;
  }

private:
  unordered_set<string> notParlindrome{};

  bool isPalindromic(string &in) {
      if(in.size() == 0) {
        return true;
      }

      if (in.size() > 0 && in[0] == in[in.size() - 1]) {
        string s = in.substr(1, in.size());
        if (isPalindromic(s)) {
          return true;
        } else {
          notParlindrome.insert(s);
        }
      }
      return false;
  }
};

int main(int argc, char **argv) { 
    Solution slt;
    string s = "aacabdkacaa";
    auto ret = slt.longestPalindrome(s);
    cout << "result:" << ret << "\r\n";
}
