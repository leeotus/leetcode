#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> vowelStrings(vector<string> &words,
                             vector<vector<int>> &queries) {
        int num = queries.size();
        vector<int> res(num, 0);
        if (words.empty()) {
            return res;
        }
        int n = words.size();
        vector<bool> cnt(n, false);
        for (int i = 0; i < n; ++i) {
            string w = words[i];
            if (vowels.find(w[0]) != vowels.end() &&
                vowels.find(w[w.size() - 1]) != vowels.end()) {
                cnt[i] = true;
            }
        }

        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (cnt[i - 1]) {
                preSum[i] = preSum[i - 1] + 1;
            } else {
                preSum[i] = preSum[i - 1];
            }
        }
        for (int i = 0; i < num; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            res[i] = (preSum[r + 1] - preSum[l]);
        }
        return res;
    }

  private:
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
};

int main(int argc, char **argv) {
    Solution s;

    return 0;
}