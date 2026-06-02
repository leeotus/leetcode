#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int minimumRecolors(string blocks, int k) {
        if (blocks.empty()) {
            return -1;
        }
        int res = INT32_MAX;
        int left = -1, right = 0;
        int cntwt = 0;
        while (right < k) {
            if (blocks[right] == 'W') {
                ++cntwt;
            }
            ++right;
        }
        res = min(res, cntwt);
        for (; right < blocks.size(); ++right) {
            ++left;
            if (blocks[left] == 'W') {
                cntwt -= 1;
            }
            if (blocks[right] == 'W') {
                cntwt += 1;
            }
            res = min(res, cntwt);
        }
        return res;
    }
};

int main(int argc, char **argv) { return 0; }