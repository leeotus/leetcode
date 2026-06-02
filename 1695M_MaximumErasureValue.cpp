#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    int maximumUniqueSubarray(vector<int> &nums) {
        set<int> cnt;
        int left = -1, right = 0;
        int res = 0;
        int sum = 0;
        for (; right < nums.size(); ++right) {
            if (cnt.find(nums[right]) != cnt.end()) {
                while (left < right) {
                    ++left;
                    sum -= nums[left];
                    cnt.erase(nums[left]);
                    if (nums[left] == nums[right]) {
                        break;
                    }
                }
            }
            sum += nums[right];
            cnt.insert(nums[right]);
            res = max(res, sum);
        }
        return res;
    }
};

int main(int argc, char **argv) { return 0; }