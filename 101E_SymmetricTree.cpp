#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return false; // ?
        }
        vector<int> lvec{};
        vector<int> rvec{};
        inorder_traversal(root->left, lvec);
        inorder_traversal(root->right, rvec);

        return lvec == rvec;
    }
private:
    void inorder_traversal(TreeNode *node, vector<int> &vec) {
        if(node == nullptr) {
            return;
        }
        inorder_traversal(node->left, vec);
        vec.push_back(node->val);
        inorder_traversal(node->right, vec);
    }
};

int main(int argc, char **argv) {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    Solution slt;
    auto res = slt.isSymmetric(node1);
    cout << "result : " << res << "\r\n";

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;

    return 0;
}
