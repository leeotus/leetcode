#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) {
            // 已经在最后一个下标
            return true;
        }
        int jmax = nums[0];
        int cur = 0;
        while(cur <= jmax) {
            jmax = max(jmax, cur + nums[cur]);
            if (jmax >= len - 1) {
                return true;
            }
            ++cur;
        }
        return false;
    }
};

int main(int argc, char **argv) {
    
    return 0;
}