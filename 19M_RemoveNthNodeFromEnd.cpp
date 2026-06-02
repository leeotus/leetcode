#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
public:
    // condition:
    // length of linked list(sz) > 0
    // n <= sz
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int index = 0;
        int len = 0;
        ListNode *prev = nullptr;
        ListNode *front = head;
        unordered_map<int, ListNode*> prevNodeLink;
        while(front != nullptr) {
            prevNodeLink[index] = prev;

            len += 1;
            index += 1;
            prev = front;
            front = front->next;
        }
        
        int delIndex = len - n;        
        prev = prevNodeLink[delIndex];
        ListNode *tmp;
        if(prev != nullptr) {
            tmp = prev->next;
            prev->next = tmp->next;
            delete tmp;
        } else {
            // head node
            tmp = head->next;
            delete head;
            return tmp;
        }
        return head;
    }
};

int main(int argc, char **argv) {

    return 0;
}