#include "TreeNode.hpp"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res{};
        queue<TreeNode *> nodeq;

        if (root == nullptr) {
            return res;
        }

        nodeq.push(root);
        while (!nodeq.empty()) {
            int sz = nodeq.size();
            vector<int> tmp;
            for (int i = 0; i < sz; ++i) {
                TreeNode *p = nodeq.front();
                nodeq.pop();
                tmp.push_back(p->val);

                if (p->left != nullptr) {
                    nodeq.push(p->left);
                }

                if (p->right != nullptr) {
                    nodeq.push(p->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }

    // 不用队列,用截断法完成
    vector<vector<int>> levelOrder2(TreeNode *root) {
        vector<vector<int>> res{};
        if (root == nullptr) {
            return res;
        }

        vector<TreeNode *> nodev{root};
        while (!nodev.empty()) {
            int sz = nodev.size();
            vector<int> tmp;
            for (int i = 0; i < sz; ++i) {
                TreeNode *p = nodev[i];
                tmp.push_back(p->val);

                if (p->left != nullptr) {
                    nodev.push_back(p->left);
                }

                if (p->right != nullptr) {
                    nodev.push_back(p->right);
                }
            }
            res.push_back(tmp);
            nodev.erase(nodev.begin(), nodev.begin() + sz);
        }
        return res;
    }
};

int main(int argc, char **argv) { return 0; }