#include "ListNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *p = head;
        while (p != nullptr) {
            heap_push(heap, p);
            p = p->next;
        }

        ListNode *res = nullptr;
        while (!heap.empty()) {
            heap[0]->next = res;
            res = heap[0];
            heap_pop(heap);
        }
        return res;
    }

    ListNode *sortListII(ListNode *head) {
        int n = calListLen(head);
        if (n < 2) {
            return head;
        }
        int mid = n / 2;
        ListNode *L = nullptr, *R = nullptr;
        ListNode *LHead, *RHead; // 记录头结点
        ListNode *p = head;
        for (int i = 0; i < mid; ++i) {
            if (L == nullptr) {
                L = new ListNode(p->val, nullptr);
                LHead = L;
            } else {
                L->next = new ListNode(p->val, nullptr);
                L = L->next;
            }
            p = p->next;
        }
        for (int i = 0; i < n - mid; ++i) {
            if (R == nullptr) {
                R = new ListNode(p->val, nullptr);
                RHead = R;
            } else {
                R->next = new ListNode(p->val, nullptr);
                R = R->next;
            }
            p = p->next;
        }

        ListNode *sortedL = sortListII(LHead);
        ListNode *sortedR = sortListII(RHead);
        ListNode *res = Merge2Lists(sortedL, sortedR);

        // TODO: 需要删除这些被分配出去的节点,以免造成内存泄露
        deleteAllNodes(LHead);
        deleteAllNodes(RHead);

        return res;
    }

  private:
    vector<ListNode *> heap;

    void heapify(vector<ListNode *> &heap, int index, int len) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int maxIndex = index;

        // 大根堆->升序
        if ((left < len) && heap[left]->val > heap[maxIndex]->val) {
            maxIndex = left;
        }
        if ((right < len) && heap[right]->val > heap[maxIndex]->val) {
            maxIndex = right;
        }

        if (maxIndex != index) {
            swap(heap[index], heap[maxIndex]);
            heapify(heap, maxIndex, len);
        }
    }

    void heap_push(vector<ListNode *> &heap, ListNode *elem) {
        heap.push_back(elem);
        int cur = heap.size() - 1;
        while ((cur - 1) / 2 >= 0 && heap[(cur - 1) / 2]->val < elem->val) {
            swap(heap[(cur - 1) / 2], heap[cur]);
            cur = (cur - 1) / 2;
        }
        if (cur == 0) {
            heapify(heap, 0, heap.size());
        }
    }

    void heap_pop(vector<ListNode *> &heap) {
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(heap, 0, heap.size());
    }

    ListNode *Merge2Lists(ListNode *left, ListNode *right) {
        int len1 = calListLen(left);
        int len2 = calListLen(right);
        int i = 0,
            j = 0; // 其实这里也可以不用i和j来索引,可以直接通过判断lit和rit是否为空来看是否到底
        ListNode res = ListNode(0);
        ListNode *p = &res;
        ListNode *lit = left, *rit = right;
        while (i < len1 && j < len2) {
            if (lit->val < rit->val) {
                p->next = new ListNode(lit->val, nullptr);
                lit = lit->next;
                ++i;
            } else {
                p->next = new ListNode(rit->val, nullptr);
                rit = rit->next;
                ++j;
            }
            p = p->next;
        }

        while (i < len1) {
            p->next = new ListNode(lit->val, nullptr);
            lit = lit->next;
            ++i;
            p = p->next;
        }
        while (j < len2) {
            p->next = new ListNode(rit->val, nullptr);
            rit = rit->next;
            ++j;
            p = p->next;
        }

        return res.next;
    }

    // 获取链表的长度, O(n)复杂度
    int calListLen(ListNode *head) {
        if (head == nullptr) {
            return 0;
        }
        int res = 0;
        while (head != nullptr) {
            ++res;
            head = head->next;
        }
        return res;
    }

    void deleteAllNodes(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        ListNode *p = head;
        while (p != nullptr) {
            ListNode *nxt = p->next;
            delete p;
            p = nxt;
        }
    }
};

int main(int argc, char **argv) {
    Solution slt;
    ListNode *head;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    head = node1;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;

    ListNode *res = slt.sortListII(head);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\r\n";

    return 0;
}