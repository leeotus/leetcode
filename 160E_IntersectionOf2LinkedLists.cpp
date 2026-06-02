#include "ListNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0, lenb = 0;
        ListNode *it = headA;
        while (it != nullptr) {
            lena += 1;
            it = it->next;
        }
        it = headB;
        while (it != nullptr) {
            lenb += 1;
            it = it->next;
        }

        int delta = abs(lena - lenb);
        if (lena > lenb) {
            while (delta-- > 0) {
                headA = headA->next;
            }
        } else {
            while (delta-- > 0) {
                headB = headB->next;
            }
        }

        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != nullptr && pb != nullptr) {
            if (pa == pb) {
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
        }
        return nullptr;
    }
};

int main(int argc, char **argv) { return 0; }
