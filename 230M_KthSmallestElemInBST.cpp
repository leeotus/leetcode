#include "TreeNode.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    // @note k从1开始数起, 且确保树不为空
    // note 如果树大小为n(节点数量), 那么有 1 <= k <= n <= 10e4
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> stk;
        int cnt = 1;
        TreeNode *it = root;
        while (it != nullptr || !stk.empty()) {
            if (it != nullptr) {
                stk.push(it);
                it = it->left;
            } else if (!stk.empty()) {
                TreeNode *p = stk.top();
                stk.pop();
                if (cnt++ == k) {
                    return p->val;
                }
                if (p->right != nullptr) {
                    it = p->right;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char **argv) { return 0; }