#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res{};
        if (nums.empty()) {
            return res;
        }
        vector<pair<int, int>> heap; // 优先队列, first:数值, second:索引

        for (int i = 0; i < k; ++i) {
            heap_push(heap, nums[i], i);
        }
        res.push_back(heap[0].first);

        for (int i = k; i < nums.size(); ++i) {
            heap_push(heap, nums[i], i);
            while (heap[0].second <= i - k) {
                heap_pop(heap);
            }
            res.push_back(heap[0].first);
        }

        return res;
    }

  private:
    void heapify(vector<pair<int, int>> &heap, int index, int len) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int maxId = index;
        if ((left < len) && (heap[left].first > heap[maxId].first)) {
            maxId = left;
        }
        if ((right < len) && (heap[right].first > heap[maxId].first)) {
            maxId = right;
        }

        if (maxId != index) {
            // 发生了改动
            swap(heap[index], heap[maxId]);
            heapify(heap, maxId, len);
        }
    }

    void heap_push(vector<pair<int, int>> &heap, int elem, int index) {
        heap.push_back({elem, index});
        int cur = heap.size() - 1;
        while ((cur - 1) / 2 >= 0 && heap[(cur - 1) / 2].first < elem) {
            swap(heap[(cur - 1) / 2], heap[cur]);
            cur = (cur - 1) / 2;
        }
        if (cur == 0) {
            heapify(heap, 0, heap.size());
        }
    }

    void heap_pop(vector<pair<int, int>> &heap) {
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(heap, 0, heap.size());
    }
};

int main(int argc, char **argv) {
    Solution slt;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    auto res = slt.maxSlidingWindow(nums, k);
    for (auto &n : res) {
        cout << n << " ";
    }
    cout << "\r\n";
    return 0;
}