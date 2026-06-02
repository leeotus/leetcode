#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> dict(3, 0);
        for(int i =0;i<nums.size(); ++i) {
            dict[nums[i]] += 1;
        }
        int j = 0;
        for (int i = 0; i < nums.size();) {
            if(dict[j] != 0) {
                nums[i] = j;
                dict[j] -= 1;
                ++i;
            } else {
                j += 1;
            }
        }
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution slt;
    slt.sortColors(nums);
    for(auto &n : nums) {
        cout << n << " ";
    }
    cout << "\r\n";
    return 0;
}