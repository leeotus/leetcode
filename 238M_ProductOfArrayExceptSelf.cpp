#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        if (nums.empty()) {
            return vector<int>{};
        }
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> prefixProd(n, 1);
        vector<int> suffixProd(n, 1);

        prefixProd[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixProd[i] = prefixProd[i - 1] * nums[i];
        }
        suffixProd[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixProd[i] = suffixProd[i + 1] * nums[i];
        }
        res[0] = suffixProd[1];
        res[n - 1] = prefixProd[n - 2];
        for (int i = 1; i < n - 1; ++i) {
            res[i] = prefixProd[i - 1] * suffixProd[i + 1];
        }
        return res;
    }
};

int main(int argc, char **argv) { return 0; }