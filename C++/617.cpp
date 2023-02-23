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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        int root1_val = 0;
        int root2_val = 0;
        TreeNode* root1_left = nullptr;
        TreeNode* root2_left = nullptr;
        TreeNode* root1_right = nullptr;
        TreeNode* root2_right = nullptr;
        if (root1 != nullptr) {
            root1_val = root1->val;
            root1_left = root1->left;
            root1_right = root1->right;
        }
        if (root2 != nullptr) {
            root2_val = root2->val;
            root2_left = root2->left;
            root2_right = root2->right;
        }

        if (root1 || root2) {
            TreeNode* new_root = new TreeNode(root1_val + root2_val);
            new_root->left = mergeTrees(root1_left, root2_left);
            new_root->right = mergeTrees(root1_right, root2_right);
            return new_root;
        } else {
            return nullptr;
        }


        
    }
};