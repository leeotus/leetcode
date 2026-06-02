#include "ListNode.hpp"
#include <iostream>

using namespace std;

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *prev = head;
        ListNode *front = head->next;
        while (front != nullptr) {
            ListNode *tmp = front->next;
            front->next = prev;
            prev = front;
            front = tmp;
        }
        head->next = nullptr;
        return prev;
    }
};

int main(int argc, char **argv) { return 0; }