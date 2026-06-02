#include "ListNode.hpp"
#include <iostream>

using namespace std;

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *rear = head;
        ListNode *front = head;
        while (front != nullptr && front->next != nullptr) {
            rear = rear->next;
            front = front->next->next;
            if (front == rear) {
                return rear;
            }
        }
        return nullptr;
    }
};

int main(int argc, char **argv) { return 0; }