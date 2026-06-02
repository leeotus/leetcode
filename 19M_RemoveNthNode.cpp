#include "ListNode.hpp"
#include <iostream>

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *front = head;
        ListNode *rear = head;
        while (n > 0 && front != nullptr) {
            front = front->next;
            n -= 1;
        }
        if (front == nullptr && n == 0) {
            ListNode *it = head;
            head = head->next;
            delete it;
            return head;
        }

        while (front && front->next != nullptr) {
            front = front->next;
            rear = rear->next;
        }

        ListNode *it = rear->next;
        if (front == it) {
            rear->next = nullptr;
        } else {
            rear->next = it->next;
        }
        delete it;
        return head;
    }
};

int main(int argc, char **argv) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    node2->next = nullptr;
    ListNode *head = node1;
    int n = 1;

    Solution slt;
    slt.removeNthFromEnd(head, n);

    return 0;
}