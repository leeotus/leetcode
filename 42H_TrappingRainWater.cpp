#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = {0};
        if(height.size() <= 2) {
            return res;
        }
        int n = height.size();
        vector<int> leftMax(n, height[0]);
        vector<int> rightMax(n, height[n-1]);
        for (int i = 1; i < n; ++i) {
          leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
          rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        for(int i=1; i<n-1; ++i) {
            res += (min(rightMax[i], leftMax[i]) - height[i]);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution slt;
    auto ret = slt.trap(height);
    cout << "result : " << ret << "\r\n";
    return 0;
}
