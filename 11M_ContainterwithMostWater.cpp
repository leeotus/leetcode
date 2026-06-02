#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int res = 0;
      int left = 0, right = height.size() - 1;
      while(right > left) {
        int w = right - left;
        int h = min(height[left], height[right]);
        res = max(res, w * h);
        if (height[left] <= height[right]) {
            int cur = height[left];
            while (left < right && height[left] <= cur) {
              ++left;
            }
        } else {
            int cur = height[right];
            while (left < right && height[right] <= cur) {
              --right;
            }
        }
      }
      return res;
    }
};

int main(int argc, char **argv) {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution slt;
    auto res = slt.maxArea(height);
    cout << "result = " << res << "\r\n";
    return 0;
}
