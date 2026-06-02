#include "TreeNode.hpp"
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validateBST(TreeNode *node, long long lower, long long upper) {
        if(node == nullptr) {
            return true;
        }

        if(node->val <= lower || node->val >= upper) {
            return false;
        }
        
        return validateBST(node->left, lower, node->val) && validateBST(node->right, node->val, upper);
    }
};