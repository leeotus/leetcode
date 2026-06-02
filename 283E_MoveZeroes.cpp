#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        for(; right < nums.size(); ++right) {
            if(nums[right] != 0) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
                ++left;
            }
        }
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution slt;
    slt.moveZeroes(nums);
    return 0;
}