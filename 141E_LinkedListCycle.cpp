#include "ListNode.hpp"
#include <iostream>

using namespace std;

class Solution {
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        ListNode *rear = head;
        ListNode *front = head->next;
        while (front != nullptr && front->next != nullptr) {
            if (front == rear) {
                return true;
            }
            rear = rear->next;
            front = front->next->next;
        }
        return false;
    }
};

int main(int argc, char **argv) { return 0; }