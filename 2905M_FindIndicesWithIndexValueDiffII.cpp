#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findIndices(vector<int> &nums, int indexDifference,
                            int valueDifference) {
        if (nums.size() < indexDifference) {
            return vector<int>{-1, -1};
        }
        int maxv = nums[0];
        int maxi = 0;
        int minv = nums[0];
        int mini = 0;
        for (int i = indexDifference; i < nums.size(); ++i) {

            // 更新maxv与maxi
            if (nums[i - indexDifference] > maxv) {
                maxv = nums[i - indexDifference];
                maxi = i - indexDifference;
            }
            // 更新minv与mini
            if (nums[i - indexDifference] < minv) {
                minv = nums[i - indexDifference];
                mini = i - indexDifference;
            }

            int v1 = abs(maxv - nums[i]);
            if (v1 >= valueDifference) {
                return vector<int>{maxi, i};
            }
            int v2 = abs(minv - nums[i]);
            if (v2 >= valueDifference) {
                return vector<int>{mini, i};
            }
        }
        return vector<int>{-1, -1};
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {7, 6, 3, 5, 9, 5};
    int indexDiff = 2;
    int valueDiff = 6;
    Solution s;
    vector<int> res = s.findIndices(nums, indexDiff, valueDiff);
    for (auto &it : res) {
        cout << it << " ";
    }
    cout << "\r\n";
    return 0;
}