#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res{};
        if (intervals.empty()) {
            return res;
        }

        quickSort(intervals, 0, intervals.size() - 1);

        for (int i = 0; i < intervals.size(); ++i) {
            vector<int> cur = intervals[i];
            int last = cur
                [1]; // 当前区间的最晚时刻,不加这个变量也可以的,直接用cur[1]判断
            int j = i + 1;
            for (; j < intervals.size(); ++j) {
                if (intervals[j][0] <= last) {
                    if (j == intervals.size() - 1) {
                        cur[1] = max(cur[1], intervals[j][1]);
                        res.push_back(cur);
                        return res;
                    }
                    cur[1] = max(cur[1], intervals[j][1]);
                    last = max(cur[1], intervals[j][1]);
                } else {
                    res.push_back(cur);
                    break;
                }
            }
            i = j - 1;
        }

        res.push_back(intervals.back());

        return res;
    }

  private:
    // 对起始时间进行快排
    int partition(vector<vector<int>> &arr, int left, int right) {
        int pivot = arr[right][0];
        int pos = left;
        for (int i = left; i < right; ++i) {
            if (arr[i][0] < pivot) {
                swap(arr[pos], arr[i]);
                pos += 1;
            }
        }
        swap(arr[pos], arr[right]);
        return pos;
    }

    void quickSort(vector<vector<int>> &arr, int left, int right) {
        if (left < right) {
            int pos = partition(arr, left, right);
            quickSort(arr, left, pos - 1);
            quickSort(arr, pos + 1, right);
        }
    }
};

int main(int argc, char **argv) {
    // vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> intervals = {{1, 4}, {1, 5}};
    vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    Solution slt;
    auto res = slt.merge(intervals);
    for (auto &v : res) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "\r\n";
    }
    return 0;
}