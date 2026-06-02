#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int countBeautifulPairs(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = 0;
        vector<int> firstNumDict(10, 0);
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            for (int i = 1; i < 10; ++i) {
                if (gcd(cur % 10, i) == 1) {
                    res += firstNumDict[i];
                }
            }
            while (cur >= 10) {
                cur /= 10;
            }
            firstNumDict[cur] += 1;
        }
        return res;
    }

  private:
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
};

int main(int argc, char **argv) { return 0; }