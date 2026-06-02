#include "TreeNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convertor(nums, 0, nums.size()-1);
    }
    
private:
    TreeNode *convertor(vector<int> &nums, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        
        int mid = left + (right - left) / 2;
        
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = convertor(nums, left, mid - 1);
        node->right = convertor(nums, mid + 1, right);
        return node;
    }
};

int main(int argc, char **argv) {
    return 0;
}
