#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int res = 0;
        if (arr.empty()) {
            return 0;
        }

        int left = -1, right = 0;
        int sum = 0;
        while (right < k) {
            sum += arr[right];
            ++right;
        }
        double th = (double)(sum) / (double)(k);
        if (th >= threshold) {
            res += 1;
        }

        for (; right < arr.size(); ++right) {
            ++left;
            sum -= arr[left];
            sum += arr[right];
            double cur = (double)(sum) / (double)(k);
            if (cur >= threshold) {
                res += 1;
            }
        }

        return res;
    }
};

int main(int argc, char **argv) { return 0; }