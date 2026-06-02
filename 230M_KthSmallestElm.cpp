#include "TreeNode.hpp"
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    // @note 0 <= node->val <= 10e4
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) {
            return -1;
        }
        
        TreeNode *p = root;
        stack<TreeNode*> pstk;
        
        int cnt = 0;
        while(p != nullptr || !pstk.empty()) {
            if(p != nullptr) {
                pstk.push(p);
                p = p->left;
            } else if(!pstk.empty()) {
                TreeNode *node = pstk.top();
                pstk.pop();
                
                ++cnt;
                if(cnt == k) {
                    return node->val;
                }

                if(node->right != nullptr) {
                    p = node->right;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char **argv) {
    return 0;
}