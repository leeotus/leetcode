#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.size() <= 1) {
            return false;
        }
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            bool hasDifferentJump = false; // 在一个循环里是否有反方向的跳跃
            bool positiveJump = true;   // 默认这次找循环的跳跃是正向的
            if (nums[i] < 0) {
                positiveJump = false;
            }
            int begin = i;
            int prev = i, front = i;
            while (front != begin) {
                if ((positiveJump && nums[front] < 0) ||
                    (!positiveJump && nums[front] > 0)) {
                    // 这次的跳跃不会是循环
                    hasDifferentJump = true;
                    break;
                }
                prev = front;
                front = (len + front + nums[front]) % len;
            }
            if(!hasDifferentJump && front != prev) {
                // 循环长度必须大于1
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char **argv) {
    // vector<int> nums = {-1, -2, -3, -4, -5, 6};
    // vector<int> nums = {1, -1, 5, 1, 4};
    // vector<int> nums = {2, -1, 1, 2, 2};
    // vector<int> nums = {-1, -2, -3, -4, -5};
    vector<int> nums = {2, -1, 1, -2, -2};

    Solution slt;
    auto ret = slt.circularArrayLoop(nums);
    cout << "result:" << (ret ? "true" : "false") << "\r\n";
    return 0;
}