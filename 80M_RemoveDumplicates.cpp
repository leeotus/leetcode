#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret {0};
        if(nums.size() <= 2) {
            return nums.size();
        }
        int i = 2;
        ret = 2;
        for(; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 2]) {
                if (i + 1 < nums.size()) {
                    nums[i] = nums[i+1];
                }
            } else {
                ret += 1;
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution slt;
    int ret = slt.removeDuplicates(nums);
    for(auto &i : nums) {
        cout << i << " ";
    }
    cout << "\r\n";
    cout << "result:" << ret << "\r\n";
    return 0;
}