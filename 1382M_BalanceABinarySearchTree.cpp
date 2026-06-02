#include "TreeNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    TreeNode *balanceBST(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        // 中序遍历放到数组中去
        vector<int> inorder{};
        inorderTree(root, inorder);
        if (inorder.empty()) {
            // 正常应该不会跑到这
            return nullptr;
        }

        return buildFromInorder(inorder, 0, inorder.size() - 1);
    }

  private:
    void inorderTree(TreeNode *node, vector<int> &v) {
        if (node == nullptr) {
            return;
        }
        inorderTree(node->left, v);
        v.push_back(node->val);
        inorderTree(node->right, v);
    }

    TreeNode *buildFromInorder(vector<int> &in, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode(in[mid]);
        node->left = buildFromInorder(in, left, mid - 1);
        node->right = buildFromInorder(in, mid + 1, right);
        return node;
    }
};

int main(int argc, char **argv) { return 0; }