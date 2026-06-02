#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1) {
            return;
        }
        int i = nums.size() - 1;
        for (; i - 1 >= 0; --i) {
            if (nums[i - 1] < nums[i]) {
                break;
            }
        }
        int j = i;
        for (; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                break;
            }
        }
        j = j < 0 ? 0 : j;
        int k = i;
        while (k + 1 < nums.size() && nums[k + 1] > nums[j]) {
            ++k;
        }
        swap(nums[k], nums[j]);
        sort(nums.begin() + i, nums.end());
    }
};

int main(int argc, char **argv) {
    // vector<int> nums = {2, 3, 1};
    vector<int> nums = {1, 3, 2};
    // vector<int> nums = {1, 1, 5};
    // vector<int> nums = {3, 2, 1};
    Solution slt;
    slt.nextPermutation(nums);
    for(auto &n : nums) {
        cout << n << " ";
    }
    cout << "\r\n";
    return 0;
}