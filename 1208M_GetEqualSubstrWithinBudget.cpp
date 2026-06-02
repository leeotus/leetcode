#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0;
        int cost = 0;
        if (s.empty()) {
            return 0;
        }
        int left = -1, right = 0;
        for (; right < s.size(); ++right) {
            char tc = t[right];
            char sc = s[right];
            cost += abs(tc - sc);
            if (cost > maxCost) {
                while (left + 1 <= right && cost > maxCost) {
                    tc = t[left + 1];
                    sc = s[left + 1];
                    cost -= abs(tc - sc);
                    ++left;
                }
            }
            res = max(res, right - left);
        }
        return res;
    }
};

int main(int argc, char **argv) { return 0; }