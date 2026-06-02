#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // @note 1 <= target <= 40, 2 <= candidates[i] <= 40
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        if (candidates.empty()) {
            return res;
        }
        targetTotal = target;

        vector<int> curNum;
        backtracking(candidates, 0, 0, curNum);
        return res;
    }

  private:
    vector<vector<int>> res{};
    int targetTotal;

    void backtracking(vector<int> &candidates, int startIndex, int curSum,
                      vector<int> &curNums) {
        if (curSum == targetTotal) {
            res.push_back(curNums);
        }
        if (curSum > targetTotal) {
            return;
        }
        if (startIndex >= candidates.size()) {
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            curSum += candidates[i];
            curNums.push_back(candidates[i]);
            // 下面使用的是i而不是startIndex是因为这题要的是组合而不是排序
            backtracking(candidates, i, curSum, curNums);
            curNums.pop_back();
            curSum -= candidates[i];
        }
    }
};

int main(int argc, char **argv) {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution slt;
    auto res = slt.combinationSum(candidates, target);
    for (auto v : res) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << "\r\n";
    }
    return 0;
}