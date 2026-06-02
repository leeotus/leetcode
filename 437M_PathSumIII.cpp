#include "TreeNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        pathSumFromNode(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return res;
    }

  private:
    int res{0};

    // 路径总和III
    void pathSumFromNode(TreeNode *node, int targetSum) {
        if (node == nullptr) {
            return;
        }

        if (node->val == targetSum) {
            res++;
        }

        pathSumFromNode(node->left, targetSum - node->val);
        pathSumFromNode(node->right, targetSum - node->val);
    }
};

int main(int argc, char **argv) { return 0; }