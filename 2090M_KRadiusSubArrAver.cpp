#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> getAverages(vector<int> &nums, int k) {
        vector<int> res{};
        if (k > (nums.size() - 1) / 2) {
            return vector<int>(nums.size(), -1);
        }
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += (long long)nums[i];
            res.push_back(-1);
        }
        int left = -1, right = k;

        // k 在此处一定小于等于nums.size() / 2了
        while (right < nums.size() && right <= 2 * k) {
            sum += (long long)nums[right];
            ++right;
        }
        int cur = sum / (2 * k + 1);
        res.push_back(cur);
        for (; right < nums.size(); ++right) {
            ++left;
            sum -= (long long)nums[left];
            sum += (long long)nums[right];
            int cur = sum / (2 * k + 1);
            res.push_back(cur);
        }
        int cnt = nums.size() - res.size();
        for (int i = 0; i < cnt; ++i) {
            res.push_back(-1);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k = 3;
    auto res = s.getAverages(nums, k);
    for (auto &r : res) {
        cout << r << " ";
    }
    cout << "\r\n";
    return 0;
}