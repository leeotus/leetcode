#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void reverseString(vector<char> &s) {
        int i = 0;
        int len = s.size();
        char cur;

        for (; i < len / 2; ++i) {
            cur = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = cur;
        }
    }
};