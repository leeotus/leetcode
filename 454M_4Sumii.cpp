#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4) {
        int n = nums1.size();
        if (n == 0) {
            return 0;
        }
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt[nums1[i] + nums2[j]] += 1;
            }
        }

        int res = 0;
        for (int k = 0; k < n; ++k) {
            for (int l = 0; l < n; ++l) {
                int sum = nums3[k] + nums4[l];
                if (cnt.find(-sum) != cnt.end()) {
                    res += cnt[-sum];
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv) { return 0; }