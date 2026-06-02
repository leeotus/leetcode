#include "TreeNode.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    // @note preorder和inorder中均无重复元素
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() != inorder.size() || preorder.empty() ||
            inorder.empty()) {
            return nullptr;
        }

        // 对inorder中序遍历构造索引
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        int preOrderIndex = 0;
        return building(preorder, preOrderIndex, inorder, inorderIndex, 0,
                        inorder.size() - 1);
    }

  private:
    TreeNode *building(vector<int> &preorder, int &preOrderIndex,
                       vector<int> &inorder,
                       unordered_map<int, int> &inorderIndex, int leftIndex,
                       int rightIndex) {
        if (leftIndex > rightIndex || preOrderIndex >= preorder.size()) {
            return nullptr;
        }

        TreeNode *node = new TreeNode(preorder[preOrderIndex]);

        // 正常应该是必须得找得到的
        int midIndex = inorderIndex[preorder[preOrderIndex]];

        preOrderIndex++;
        node->left = building(preorder, preOrderIndex, inorder, inorderIndex,
                              leftIndex, midIndex - 1);
        node->right = building(preorder, preOrderIndex, inorder, inorderIndex,
                               midIndex + 1, rightIndex);
        return node;
    }
};

int main(int argc, char **argv) {
    vector<int> preorder = {1, 2};
    vector<int> inorder = {1, 2};

    Solution slt;
    slt.buildTree(preorder, inorder);

    return 0;
}