#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int len = nums.size();
        vector<int> imax(len);
        vector<int> imin(len);
        int ret = nums[0];
        imax[0] = imin[0] = nums[0];
        for(int i = 1; i < len; ++i) {
            if(nums[i] > 0) {
                imax[i] = max(imax[i-1] * nums[i], nums[i]);
                imin[i] = min(imin[i-1] * nums[i], nums[i]);
            } else if(nums[i] < 0) {
                imax[i] = max(imin[i-1] * nums[i], nums[i]);
                imin[i] = min(imax[i-1] * nums[i], nums[i]);
            }
            ret = max(ret, imax[i]);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {2, 3, -2, 4};
    Solution slt;
    auto ret = slt.maxProduct(nums);
    cout << "result:" << ret << "\r\n";
    return 0;
}