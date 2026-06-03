#include <string>

using namespace std;

class Solution {
  public:
    string reversePrefix(string s, int k) {
        if (s.empty()) {
            return s;
        }
        int left = 0, right = k - 1;
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
        return s;
    }
};