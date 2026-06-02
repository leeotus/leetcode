#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int v) {
        val = v;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map<Node *, Node *> deliver;
        Node dummy = Node(0);
        Node *node = &dummy;

        Node *it = head;
        while (it != nullptr) {
            Node *p = new Node(it->val);
            p->random = it->random;
            node->next = p;
            node = node->next;

            deliver[it] = p;
            it = it->next;
        }

        node = dummy.next;
        while (node != nullptr) {
            if (node->random != nullptr) {
                node->random = deliver[node->random];
            }
            node = node->next;
        }

        return dummy.next;
    }
};

int main(int argc, char **argv) {
    Solution slt;
    return 0;
}
