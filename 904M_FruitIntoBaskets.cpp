#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int totalFruit(vector<int> &fruits) {
        int res = 0;
        if (fruits.empty()) {
            return 0;
        }
        int left = -1, right = 0;
        vector<int> basket;
        for (; right < fruits.size(); ++right) {
            if (basket.size() < 2) {
                basket.push_back(fruits[right]);
            } else if (basket.size() == 2 && fruits[right] != basket[0] &&
                       fruits[right] != basket[1]) {
                int tmp = right - 1;
                while (tmp - 1 >= 0 && fruits[tmp] == fruits[tmp - 1]) {
                    --tmp;
                }
                left = tmp - 1;
                basket.clear();
                basket.push_back(fruits[tmp]);
                basket.push_back(fruits[right]);
            }
            int len = right - left;
            res = max(res, len);
        }
        return res;
    }
};

int main(int argc, char **argv) { return 0; }