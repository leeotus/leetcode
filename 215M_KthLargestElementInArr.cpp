#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // @note nums.size() > k
    int findKthLargest(vector<int> &nums, int k) {
        vector<int> heap;
        for (int i = 0; i < nums.size(); ++i) {
            heap_push(heap, nums[i]);
        }
        int cnt = 1;
        while (cnt < k) {
            heap_pop(heap);
            ++cnt;
        }
        return heap[0];
    }

  private:
    void heapify(vector<int> &heap, int index, int len) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int maxId = index;
        if ((left < len) && (heap[left] > heap[maxId])) {
            maxId = left;
        }
        if ((right < len) && (heap[right] > heap[maxId])) {
            maxId = right;
        }
        if (maxId != index) {
            swap(heap[maxId], heap[index]);
            heapify(heap, maxId, len);
        }
    }

    void heap_push(vector<int> &heap, int elem) {
        heap.push_back(elem);
        int cur = heap.size() - 1;
        while ((cur - 1) / 2 >= 0 && (heap[(cur - 1) / 2] < elem)) {
            swap(heap[(cur - 1) / 2], heap[cur]);
            cur = (cur - 1) / 2;
        }
        if (cur == 0) {
            heapify(heap, 0, heap.size());
        }
    }

    void heap_pop(vector<int> &heap) {
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(heap, 0, heap.size());
    }
};

int main(int argc, char **argv) {
    Solution slt;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int res = slt.findKthLargest(nums, k);
    cout << "result:" << res << "\r\n";
    return 0;
}