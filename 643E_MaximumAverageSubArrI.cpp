#include <vector>

using namespace std;

class Solution {
  public:
    // @note k <= nums.size()
    double findMaxAverage(vector<int> &nums, int k) {
        int left = -1, right = 0;
        int sum = 0;
        while (right < k) {
            sum += nums[right];
            ++right;
        }
        double res = (double)((double)(sum) / (double)k);
        for (; right < nums.size(); ++right) {
            ++left;
            sum -= nums[left];
            sum += nums[right];
            double cur = (double)((double)(sum) / (double)(k));
            res = max(res, cur);
        }
        return res;
    }
};

int main(int argc, char **argv) { return 0; }