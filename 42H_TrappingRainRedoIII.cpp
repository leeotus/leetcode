#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if(height.empty()) {
            return res;
        }
        int s = height.size();
        vector<int> leftView(s, 0);
        vector<int> rightView(s, 0);

        int leftMax = height[0];
        for (int i = 1; i < s; ++i) {
            if(height[i] >= leftMax) {
                leftMax = height[i];
                leftView[i] = 0;
            } else {
                leftView[i] = leftMax - height[i];
            }
        }
        
        int rightMax = height[s-1];
        for (int j = s - 2; j >= 0; --j) {
            if(height[j] >= rightMax) {
                rightMax = height[j];
                rightView[j] = 0;
            } else {
                rightView[j] = rightMax - height[j];
            }
        }

        for (int k = 0; k < s; k++) {
            res += min(leftView[k], rightView[k]);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution slt;
    int res = slt.trap(height);
    cout << "result:" << res << "\r\n";
    return 0;
}