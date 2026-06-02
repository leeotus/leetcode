#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        int len = queries.size();
        vector<int> res(len, 0);
        if (nums.empty() || len == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> preSum(nums.size() + 1, 0);
        for (int i = 1; i < preSum.size(); ++i) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        for (int i = 0; i < len; ++i) {
            int j = 0;
            int q = queries[i];
            for (; j < preSum.size(); ++j) {
                if (j + 1 < preSum.size() && preSum[j + 1] > q) {
                    res[i] = j;
                    break;
                }
            }
            if (j == preSum.size()) {
                res[i] = j - 1;
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums = {4, 5, 2, 1};
    vector<int> queries = {3, 10, 21};
    auto res = s.answerQueries(nums, queries);
    for (auto &it : res) {
        cout << it << " ";
    }
    cout << "\r\n";
    return 0;
}