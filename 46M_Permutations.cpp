#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
        res.clear();
        res.shrink_to_fit();
        if (nums.empty()) {
            return res;
        }
        vector<bool> used(nums.size(), false);
        vector<int> path;
        backtracking(nums, 0, path, used);
        return res;
    }

  private:
    vector<vector<int>> res{};

    void backtracking(vector<int> &nums, int startIndex, vector<int> &path,
                      vector<bool> &used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i < nums.size() + startIndex; ++i) {
            int cur = i % nums.size();
            if (used[cur])
                continue;
            path.push_back(nums[cur]);
            used[cur] = true;
            backtracking(nums, i + 1, path, used);
            path.pop_back();
            used[cur] = false;
        }
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {0, 1};
    Solution slt;
    auto res = slt.permute(nums);
    for (auto vec : res) {
        for (auto &n : vec) {
            cout << n << " ";
        }
        cout << "\r\n";
    }
    return 0;
}