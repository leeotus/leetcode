#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> total;
        for (int i = 0; i < nums.size(); ++i) {
            total[nums[i]] += 1;
        }

        vector<int> res{};
        vector<pair<int, int>> heap;
        for (auto &it : total) {
            heap_push(heap, it.first, it.second);
        }

        int cnt = 0;
        while (cnt < k) {
            res.push_back(heap[0].first);
            heap_pop(heap);
            ++cnt;
        }

        return res;
    }

  private:
    void heapify(vector<pair<int, int>> &heap, int index, int len) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int maxId = index;

        if ((left < len) && (heap[left].second > heap[maxId].second)) {
            maxId = left;
        }
        if ((right < len) && (heap[right].second > heap[maxId].second)) {
            maxId = right;
        }

        if (maxId != index) {
            swap(heap[maxId], heap[index]);
            heapify(heap, maxId, len);
        }
    }

    void heap_push(vector<pair<int, int>> &heap, int elem, int freq) {
        heap.push_back({elem, freq});
        int cur = heap.size() - 1;
        while ((cur - 1) / 2 >= 0 && (heap[(cur - 1) / 2].second < freq)) {
            swap(heap[cur], heap[(cur - 1) / 2]);
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
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution slt;
    auto res = slt.topKFrequent(nums, k);
    for (auto &n : res) {
        cout << n << " ";
    }
    cout << "\r\n";
    return 0;
}