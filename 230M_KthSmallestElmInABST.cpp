#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    if (root == nullptr) {
      return -1; // not happen
    }

    stack<TreeNode *> stk;
    int cur = 1;
    TreeNode *node = root;
    while (node != nullptr || !stk.empty()) {
      while (node != nullptr) {
        stk.push(node);
        node = node->left;
      }
      while (!stk.empty()) {
        TreeNode *p = stk.top();
        stk.pop();
        if (cur == k) {
          return p->val;
        }
        ++cur;
        if (p->right != nullptr) {
          node = p->right;
          break;
        }
      }
    }
    return -1;
  }
};

int main(int argc, char **argv) {
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(2);
    node3->left = node1;
    node3->right = node4;
    node1->right = node2;
    TreeNode *root = node3;

    Solution slt;
    int k = 2;
    auto res = slt.kthSmallest(root, k);
    cout << "result: " << res << "\r\n";

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    return 0;
}
