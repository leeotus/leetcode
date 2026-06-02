#include "TreeNode.hpp"
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return false;
        }
        return validate(root, LONG_MIN, LONG_MAX);
    }

  private:
    bool validate(TreeNode *node, long long minVal, long long maxVal) {
        if (node == nullptr) {
            return true;
        }
        if (node->val < minVal || node->val > maxVal) {
            return false;
        }

        int mid = node->val;
        return validate(node->left, minVal, mid) &&
               validate(node->right, mid, maxVal);
    }
};

int main(int argc, char **argv) { return 0; }