#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x,
                                         int y, int k) {
        if (grid.empty()) {
            return grid;
        }
        int ys = y, ye = y + k - 1;
        int xs = x, xe = x + k - 1;
        for (int j = ys; j <= ye; ++j) {
            int left = xs, right = xe;
            while (left < right) {
                swap(grid[left][j], grid[right][j]);
                ++left;
                --right;
            }
        }
        return grid;
    }
};