#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ret{0};
        if(height.empty()) {
            return 0;
        }
        int len = height.size();
        int left_h = height[0];
        int right_h = height[len-1];
        vector<int> left_water(len, 0), right_water(len, 0);
        for(int i = 0; i < len; ++i) {
            if (height[i] > left_h) {
                left_h = height[i];
            } else {
                left_water[i] = (left_h - height[i]);
            }
        }
        for (int j = len - 1; j >= 0; --j) {
            if(height[j] > right_h) {
                right_h = height[j];
            } else {
                right_water[j] = (right_h - height[j]);
            }
        }
        
        for(int k = 0; k < len; ++k) {
            ret += min(left_water[k], right_water[k]);
        }
        return ret;
    }
};
int main(int argc, char **argv) {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution slt;
    int ret = slt.trap(heights);
    cout << "result:" << ret << "\r\n";
    return 0;
}