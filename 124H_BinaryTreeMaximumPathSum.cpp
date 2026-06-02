#include "TreeNode.hpp"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxPathSum(TreeNode *root) {
        maxGainFromNode(root);
        return maxGain;
    }

  private:
    int maxGain = INT32_MIN;

    int maxGainFromNode(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int leftGain = max(maxGainFromNode(node->left), 0);
        int rightGain = max(maxGainFromNode(node->right), 0);
        int curGain = node->val + leftGain + rightGain;
        maxGain = max(maxGain, curGain);

        return node->val + max(leftGain, rightGain);
    }
};

int main(int argc, char **argv) { return 0; }