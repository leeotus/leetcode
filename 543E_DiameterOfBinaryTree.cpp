#include "TreeNode.hpp"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int diameterOfBinaryTree(TreeNode *root) {
        maxDimFromNode(root);
        return maxDim;
    }

  private:
    int maxDim = INT32_MIN;

    int maxDimFromNode(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDim = maxDimFromNode(node->left);
        int rightDim = maxDimFromNode(node->right);

        maxDim = max(maxDim, leftDim + rightDim);

        return max(leftDim, rightDim) + 1;
    }
};

int main(int argc, char **argv) {
    TreeNode *root = new TreeNode(1, nullptr, nullptr);
    TreeNode *leaf = new TreeNode(2, nullptr, nullptr);
    root->left = leaf;
    Solution slt;
    int res = slt.diameterOfBinaryTree(root);
    cout << "result:" << res << "\r\n";
    return 0;
}