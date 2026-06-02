#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxScoreSightseeingPair(vector<int> &values) {
        if (values.size() < 2) {
            return 0;
        }
        unordered_map<int, int> dict;
        int res = 0;
        int curMax = values[0];
        dict[curMax] = 0;
        for (int j = 1; j < values.size(); ++j) {
            int i = dict[curMax];
            int val = curMax + values[j] + i - j;
            res = max(res, val);
            while (++i < j) {
                int val2 = values[i] + values[j] + i - j;
                res = max(res, val2);
            }
            dict[values[j]] = j;
            if (values[j] > curMax) {
                curMax = values[j];
            }
        }
        return res;
    }

    int maxScoreSightseesingPairII(vector<int> &values) {
        if (values.size() < 2) {
            return 0;
        }
        int res = 0;
        int maxvi = values[0];
        for (int j = 1; j < values.size(); ++j) {
            int cur = maxvi + values[j] - j;
            res = max(res, cur);
            maxvi = max(maxvi, values[j] + j);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> values = {8, 1, 5, 2, 6};
    Solution slt;
    int res = slt.maxScoreSightseeingPair(values);
    cout << "result:" << res << "\r\n";
    return 0;
}