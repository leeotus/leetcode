#include "TreeNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        process(root);
    }

    // 探索更高效的做法:
    // 1. 先序遍历树, 将节点指针保存
    // 2. 遍历数组, 将节点指针重新连接成链表
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeNode *p = root;
        while (p != nullptr) {
            if (p->left != nullptr) {
                TreeNode *r = p->right;
                p->right = p->left;
                p->left = nullptr;
                TreeNode *q = p->right;
                while (q->right != nullptr) {
                    q = q->right;
                }
                q->right = r;
            }
            p = p->right;
        }
    }

  private:
    TreeNode *process(TreeNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        TreeNode *r = node->right;
        node->right = process(node->left);
        node->left = nullptr;
        TreeNode *p = node;
        while (p->right != nullptr) {
            p = p->right;
        }
        p->right = process(r);
        return node;
    }
};

int main(int argc, char **argv) { return 0; }