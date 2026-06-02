#include "TreeNode.hpp"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res = {};
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode *> nodeq;
        nodeq.push(root);
        while(!nodeq.empty()) {
            int s = nodeq.size();
            for(int i = 0; i < s; ++i) {
                TreeNode *p = nodeq.front();
                nodeq.pop();
                if(i == s - 1) {
                    res.push_back(p->val);
                }

                if(p->left != nullptr) {
                    nodeq.push(p->left);
                }
                if(p->right != nullptr) {
                    nodeq.push(p->right);
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    return 0;
}