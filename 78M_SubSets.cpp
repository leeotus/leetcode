#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.empty()) {
            return res;
        }
        vector<int> path;
        backtracking(nums, 0, path);
        return res;
    }

  private:
    vector<vector<int>> res;

    void backtracking(vector<int> &nums, int startIndex, vector<int> &path) {
        res.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1, path);
            path.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1, 2, 3};

    Solution slt;
    auto res = slt.subsets(nums);
    for (auto v : res) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << "\r\n";
    }

    return 0;
}