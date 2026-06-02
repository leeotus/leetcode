#include "TreeNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> vxl;
        if(root == nullptr) {
            return;
        }
        
        flattenProcess(root, vxl);

        for (int i = 1; i < vxl.size(); ++i) {
            TreeNode *next = vxl[i];
            TreeNode *prev = vxl[i-1];
            prev->right = next;
            prev->left = nullptr;
        }
    }
private:

    void flattenProcess(TreeNode *node, vector<TreeNode*> &l) {
        if(node != nullptr) {
            l.push_back(node);
            flattenProcess(node->left, l);
            flattenProcess(node->right, l);
        }
    }
};

int main(int argc, char **argv) {
    return 0;
}