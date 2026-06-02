#include "ListNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    vector<ListNode *> heap;

    // @brief push元素到小根堆
    void heap_push(vector<ListNode *> &heap, ListNode *it) {
        heap.push_back(it);
        int cur = heap.size() - 1;
        while ((cur - 1) / 2 >= 0 && heap[(cur - 1) / 2]->val > it->val) {
            swap(heap[(cur - 1) / 2], heap[cur]);
            cur = (cur - 1) / 2;
        }
        if (cur == 0) {
            heapify(heap, 0, heap.size());
        }
    }

    // @brief 从小根堆中pop元素
    void heap_pop(vector<ListNode *> &heap) {
        if (!heap.empty()) {
            swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            heapify(heap, 0, heap.size());
        }
    }

    // @brief 小根堆
    void heapify(vector<ListNode *> &heap, int index, int len) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int maxId = index;

        if ((left < len) && (heap[left]->val < heap[maxId]->val)) {
            maxId = left;
        }

        if ((right < len) && (heap[right]->val < heap[maxId]->val)) {
            maxId = right;
        }

        if (maxId != index) {
            swap(heap[maxId], heap[index]);
            heapify(heap, maxId, len);
        }
    }

    ListNode *heap2List(vector<ListNode *> &heap) {
        ListNode dummy = ListNode(0);
        ListNode *p = &dummy;
        while (!heap.empty()) {
            p->next = heap[0];
            p = p->next;
            p->next = nullptr;
            heap_pop(heap);
        }
        return dummy.next;
    }

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }
        for (int i = 0; i < lists.size(); ++i) {
            ListNode *it = lists[i];
            while (it != nullptr) {
                // todo: heap_push function
                heap_push(heap, it);
                it = it->next;
            }
        }
        return heap2List(heap);
    }
};

int main(int argc, char **argv) {
    ListNode *node1 = new ListNode(-2);
    ListNode *node2 = new ListNode(-1);
    ListNode *node3 = new ListNode(-1);
    ListNode *node4 = new ListNode(-1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    vector<ListNode *> lists = {node1, {}};
    Solution slt;
    ListNode *res = slt.mergeKLists(lists);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\r\n";
    return 0;
}