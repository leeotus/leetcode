#include "ListNode.hpp"
#include <iostream>

using namespace std;

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }

        ListNode *front = head;
        ListNode *rear = head;
        int cnt = 1;
        while (cnt < k && front != nullptr) {
            ++cnt;
            front = front->next;
        }

        if (front == nullptr && cnt != k) {
            return head;
        } else {
            head = front;
        }

        if (front != nullptr) {
            ListNode *nextHead = front->next;
            reverseKLink(rear, front)->next = reverseKGroup(nextHead, k);
        }
        return head;
    }

  private:
    ListNode *reverseKLink(ListNode *head, ListNode *last) {
        ListNode *rear = head;
        ListNode *front = head->next;

        while (front && front != last->next) {
            ListNode *tmp = front->next;
            front->next = rear;
            rear = front;
            front = tmp;
        }

        // 返回翻转链表的最后一个元素
        return head;
    }
};

int main(int argc, char **argv) {
    Solution slt;
    ListNode *head;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    int k = 2;

    ListNode *res = slt.reverseKGroup(head, k);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\r\n";
    return 0;
}