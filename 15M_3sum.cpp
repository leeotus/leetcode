#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res{};
        if(nums.size() < 3) {
            return res;
        }
        int i, j, k;
        sort(nums.begin(), nums.end());
        for (i = 0; i <= nums.size() - 3; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            j = i+1;
            k = nums.size() - 1;
            while(k > j) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                  res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                  while(k > j && nums[k] == nums[k-1]) {
                    --k;
                  }
                  --k;
                  while(k > j && nums[j] == nums[j+1]) {
                    ++j;
                  }
                  ++j;
                } else if(sum > 0) {
                  --k;
                } else {
                  ++j;
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution slt;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto res = slt.threeSum(nums);
    for(auto &v : res) {
        for(auto &n : v) {
            cout << n << " ";
        }
        cout << "\r\n";
    }
    return 0;
}
