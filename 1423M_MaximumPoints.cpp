#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxScore(vector<int> &cardPoints, int k) {
        if (cardPoints.empty()) {
            return 0;
        }
        int res = 0;
        int sum = 0;
        if (k >= cardPoints.size()) {
            for (auto &p : cardPoints) {
                sum += p;
            }
            return sum;
        }

        // 一左一右拿去卡牌
        int left = 0, right = cardPoints.size();
        while (left < k) {
            sum += cardPoints[left];
            ++left;
        }
        left -= 1;
        res = max(res, sum);
        for (; left >= 0; --left) {
            --right;
            sum -= cardPoints[left];
            sum += cardPoints[right];
            res = max(res, sum);
        }

        return res;
    }
};

int main(int argc, char **argv) {}