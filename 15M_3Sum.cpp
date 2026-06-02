#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res{};
        if(nums.empty()) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                }

                if (sum > 0) {
                    while (j < k && nums[k - 1] == nums[k]) {
                        k -= 1;
                    }
                    k -= 1;
                } else {
                    while (j < k && nums[j + 1] == nums[j]) {
                        j += 1;
                    }
                    j += 1;
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    return 0;
}