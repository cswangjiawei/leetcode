/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root==nullptr) {
            return true;
        }

        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (abs(left_height - right_height) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int tree_height(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        return max(tree_height(root->left), tree_height(root->right)) + 1;
    }
};