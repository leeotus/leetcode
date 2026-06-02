#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    // NOTE height.size() >= 2
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while(right > left) {
            int w = right - left;
            int h = min(height[left], height[right]);
            int s = w * h;
            res = max(res, s);

            if (height[left] < height[right]) {
                int left_h = height[left];
                while (left < right && height[left] <= left_h) {
                    ++left;
                }
            } else {
                int right_h = height[right];
                while (right > left && height[right] <= right_h) {
                    --right;
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    Solution slt;
    int res = slt.maxArea(nums);
    cout << "result:" << res << "\r\n";
    return 0;
}